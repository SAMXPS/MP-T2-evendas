<?php

session_start();

$obj = new \stdClass;
$obj->data = $_GET;
$obj->session = $_SESSION;

$json = addslashes(json_encode($obj));

$saida = shell_exec("echo $json  | ../backend/bin/test");

$saida_json = json_decode($saida);

if ($saida_json->status == "OK") {
    $_SESSION = $saida_json->session;
    echo json_encode($saida_json->data);
} else {
    echo "Saida inválida: $saida";
}