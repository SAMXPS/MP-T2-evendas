<?php

session_start();

$obj = new \stdClass;
if (!empty($_GET))
    $obj->data = $_GET;
else if (!empty($_POST))
    $obj->data = $_POST;

$obj->session = $_SESSION;

$json = addslashes(json_encode($obj));

$saida = shell_exec("echo $json  | ../backend/bin/backend");

$saida_json = json_decode($saida);

if ($json == null) {
    echo "Saida inválida: $saida";
    die();
} 

if (isset($saida_json->session))
    $_SESSION = $saida_json->session;

unset($saida_json->session);

echo json_encode($saida_json);