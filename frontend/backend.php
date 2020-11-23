<?php

session_start();

$obj = new \stdClass;
$obj->data = $_GET;
$obj->session = $_SESSION;

$json = addslashes(json_encode($obj));

$saida = shell_exec("echo $json  | ../backend/bin/test");
/*
$saida_json = json_decode();
if ($saida->status == "OK") {
    $_SESSION = $saida->session;
    echo json_encode($saida->data);
}*/

echo "<p>$saida</p>";