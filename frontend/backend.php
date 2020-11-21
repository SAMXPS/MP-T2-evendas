<?php

session_start();

$obj = new \stdClass;
$obj->data = $_GET;
$obj->session = $_SESSION;

$json = addslashes(json_encode($obj));

$saida = json_decode(shell_exec("echo $json  | ../backend/bin/test"));

if ($saida->status == "OK") {
    $_SESSION = $saida->session;
    echo json_encode($saida->data);
}