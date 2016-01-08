<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="utf-8"/>
        <meta http-equiv="X-UA-Compatible" content="IE=edge"/>
        <meta name="viewport" content="width=device-width, initial-scale=1"/>
        <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->
        <title>
            Torque Web Interface
        </title>
        <!-- Bootstrap core CSS -->
        <link href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css" rel="stylesheet"/>
        <!-- Latest compiled and minified CSS -->
        <link rel="stylesheet" href="//cdnjs.cloudflare.com/ajax/libs/bootstrap-table/1.9.1/bootstrap-table.min.css"/>
        <!-- Custom styles for this template -->
        <link href="dashboard.css" rel="stylesheet"/>
        <script src="./Chart.js/Chart.js">
        </script>
        <!-- Just for debugging purposes. Don't actually copy these 2 lines! -->
    </head>
    <body>
        <nav class="navbar navbar-inverse navbar-fixed-top">
            <div class="container-fluid">
                <div class="navbar-header">
                    <a class="navbar-brand" href="#">
                        Torque Web Interface
                    </a>
                </div>
                <div id="navbar" class="navbar-collapse collapse">
                    <ul class="nav navbar-nav navbar-right">
                        <li>
                            <a href="https://github.com/kenkoooo/torque-web">
                                Help
                            </a>
                        </li>
                    </ul>
                </div>
            </div>
        </nav>
        <div class="container">
            <div class="row">
                <h1 class="page-header">
                    Dashboard
                </h1>
                <div class="row placeholders">
                    <?php
                    foreach ($pbsnodes as $value) :
                    $node_name=(string) $value->
                    name;
                    ?>
                    <div class='col-xs-6 col-sm-3 placeholder'>
                        <canvas width='200' height='200' style='width: 100px; height: 100px;' id=
                            <?php
                            echo "'$node_name'";
                            ?>
                            >
                        </canvas>
                        <h4>
                            <?php  echo $node_name; ?>
                        </h4>
                        <span class="text-muted">
                            <?php echo $value->
                            state;?>
                        </span>
                        <script>
                            var doughnutData = [
                            <?php foreach ($node_job_counts as $owner=>
                            $value) {
                            if(!isset($value[$node_name])||$value[$node_name]==0)continue;
                            ?>
                            {
                            value:
                            <?php echo $value[$node_name];?>
                            ,
                            color:
                            <?php echo '"'.$palette[$owner].'"'; ?>
                            ,
                            label:
                            <?php echo "'$owner'"; ?>
                            },
                            <?php }?>
                            {
                            value:
                            <?php echo $job_threads[$node_name]-$job_counts[$node_name];?>
                            ,
                            color: "#58616A",
                            label: "Empty"
                            }
                            ];
                            var myDoughnut = new Chart(document.getElementById("<?php  echo $node_name; ?>").
                            getContext("2d")).Doughnut(doughnutData);
                        </script>
                    </div>
                    <?php endforeach; ?>
                    <div class='col-xs-6 col-sm-3 placeholder'>
                        <canvas width='200' height='200' style='width: 100px; height: 100px;' id="all_nodes">
                        </canvas>
                        <h4>
                            All
                        </h4>
                        <span class="text-muted">
                            <?php echo intval(array_sum($job_counts)*100/array_sum($job_threads))."% Used";?>
                        </span>
                        <script>
                            var doughnutData = [
                            <?php foreach ($node_job_counts as $owner=>
                            $value) { ?>
                            {
                            value:
                            <?php echo array_sum($value);?>
                            ,
                            color:
                            <?php echo '"'.$palette[$owner].'"'; ?>
                            ,
                            label:
                            <?php echo "'$owner'"; ?>
                            },
                            <?php }?>
                            {
                            value:
                            <?php echo array_sum($job_threads)-array_sum($job_counts);?>
                            ,
                            color: "#58616A",
                            label: "Empty"
                            }
                            ];
                            var myDoughnut = new Chart(document.getElementById("all_nodes").
                            getContext("2d")).Doughnut(doughnutData);
                        </script>
                    </div>
                </div>
                <h2 class="sub-header">
                    Jobs
                </h2>
                <div class="table-responsive">
                    <table class="table table-striped" data-toggle="table"
                        data-search="true"
                        data-sort-name="id"
                        data-sort-order="asc">
                        <thead>
                            <tr>
                                <th data-field="id" data-sortable="true" data-field="id" data-sortable="true">
                                    #
                                </th>
                                <th data-field="name" data-sortable="true">
                                    Job Name
                                </th>
                                <th data-field="owner" data-sortable="true">
                                    Owner
                                </th>
                                <th data-field="state" data-sortable="true">
                                    State
                                </th>
                                <th data-field="node" data-sortable="true">
                                    Exec Node
                                </th>
                                <th data-field="time" data-sortable="true">
                                    Used Time
                                </th>
                            </tr>
                        </thead>
                        <tbody>
                            <?php foreach ($qstat_xml->
                            Job as $value): ?>
                            <tr>
                                <td>
                                    <?php echo $value->
                                    Job_Id;?>
                                </td>
                                <td>
                                    <?php echo $value->
                                    Job_Name;?>
                                </td>
                                <td>
                                    <?php echo $value->
                                    Job_Owner;?>
                                </td>
                                <td>
                                    <?php echo $value->
                                    job_state;?>
                                </td>
                                <td>
                                    <?php echo $value->
                                    exec_host;?>
                                </td>
                                <td>
                                    <?php echo $value->
                                    resources_used->
                                    walltime;?>
                                </td>
                            </tr>
                            <?php endforeach ?>
                        </tbody>
                    </table>
                </div>
            </div>
        </div>
        <!--
            Bootstrap core JavaScript
            ==================================================
        -->
        <!-- Placed at the end of the document so the pages load faster -->
        <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.3/jquery.min.js">
        </script>
        <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/js/bootstrap.min.js">
        </script>
        <script src="//cdnjs.cloudflare.com/ajax/libs/bootstrap-table/1.9.1/bootstrap-table.min.js">
        </script>
    </body>
</html>
