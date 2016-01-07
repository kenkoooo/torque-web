<?php
$qstat_xml = simplexml_load_string(shell_exec('qstat -x'));
$pbsnodes_xml = simplexml_load_string(shell_exec('pbsnodes -x'));
include ('html.inc');
?>
