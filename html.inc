<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="utf-8"/>
        <meta http-equiv="X-UA-Compatible" content="IE=edge"/>
        <meta name="viewport" content="width=device-width, initial-scale=1"/>
        <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->
        <meta name="description" content=""/>
        <meta name="author" content=""/>
        <title>
            Dashboard Template for Bootstrap
        </title>
        <!-- Bootstrap core CSS -->
        <link href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css" rel="stylesheet"/>
        <!-- Custom styles for this template -->
        <link href="dashboard.css" rel="stylesheet"/>
        <script src="./Chart.js/Chart.js">
        </script>
        <!-- Just for debugging purposes. Don't actually copy these 2 lines! -->
    </head>
    <body>
        <nav class="navbar navbar-inverse navbar-fixed-top">
            <div class="container-fluid">
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
                    foreach ($pbsnodes_xml->
                    Node as $value) :
                    $node_name= $value->
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
                        <?php
                        $job_count=substr_count($value->
                        jobs, ',')+1;
                        ?>
                        <script>
                            var doughnutData = [
                            {
                            value:
                            <?php echo $job_count;?>
                            ,
                            color: "#fbaa6e"
                            },
                            {
                            value: 
                            <?php echo 24-$job_count;?>,
                            color: "#A8BECB"
                            }
                            ];
                            var myDoughnut = new Chart(document.getElementById("<?php  echo $node_name; ?>").
                            getContext("2d")).Doughnut(doughnutData);
                        </script>
                    </div>
                    <?php endforeach; ?>
                </div>
                <h2 class="sub-header">
                    Jobs
                </h2>
                <div class="table-responsive">
                    <table class="table table-striped">
                        <thead>
                            <tr>
                                <th>
                                    #
                                </th>
                                <th>
                                    Job Name
                                </th>
                                <th>
                                    Owner
                                </th>
                                <th>
                                    State
                                </th>
                                <th>
                                    Exec Node
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
        <script>
            window.jQuery || document.write('
            <script src="../../assets/js/vendor/jquery.min.js">
                <\/script>
                    ')
                </script>
                <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/js/bootstrap.min.js">
                </script>
            </body>
        </html>
