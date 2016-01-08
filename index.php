<?php
$qstat_xml = simplexml_load_string(shell_exec('qstat -x'));
$pbsnodes_xml = simplexml_load_string(shell_exec('pbsnodes -x'));

$pbsnodes = [];
$job_counts = [];
$job_threads = [];
foreach ($pbsnodes_xml->Node as $value) {
    $node_name = (string)$value->name;
    array_push($pbsnodes, $value);
    $job_counts[$node_name] = substr_count($value->jobs, ',') + 1;
    $job_threads[$node_name] = (int)$value->np;
}
include ('html.inc');
?>
