<?php
$qstat_xml = simplexml_load_string(shell_exec('qstat -x'));
$pbsnodes_xml = simplexml_load_string(shell_exec('pbsnodes -x'));

$pbsnodes = [];
$job_counts = [];
$job_threads = [];
foreach ($pbsnodes_xml->Node as $value) {
	$node_name = (string) $value->name;
	array_push($pbsnodes, $value);
	if (isset($value->jobs)) {
		$job_counts[$node_name] = substr_count($value->jobs, ',') + 1;
	} else {
		$job_counts[$node_name] = 0;
	}
	$job_threads[$node_name] = (int) $value->np;
}

$node_job_counts = [];
$owners = [];
foreach ($qstat_xml->Job as $value) {
	if ($value->job_state != 'R') {
		continue;
	}

	$exec_host = explode("+", (string) $value->exec_host);
	$owner = explode("@", (string) $value->Job_Owner)[0];
	$owners[] = $owner;
	foreach ($exec_host as $host) {
		$node_name = explode("/", $host)[0];
		if (!isset($node_job_counts[$owner][$node_name])) {
			$node_job_counts[$owner][$node_name] = 0;
		}

		$node_job_counts[$owner][$node_name]++;
	}
}

$owners = array_unique($owners);
$colors = ["#74A82A", "#D55511", "#3565A1", "#A42F11", "#EEA435", "#6BA2D0", "#B7C4CF", "#75D0ED"];
shuffle($colors);
$k = 0;
$palette = [];
foreach ($owners as $owner) {
	$palette[$owner] = $colors[$k];
	$k = ($k + 1) % sizeof($colors);
}
include 'html.inc';
?>
