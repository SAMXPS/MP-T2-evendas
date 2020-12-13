<?php
if (!empty($_FILES['img']['tmp_name'])) {
  $exp = explode('.', $_FILES['img']['name']);
  $ext = '.'. $exp[count($exp)-1];
  $name = md5(random_bytes(24));

  $path = "/home/evendas/sistema/frontend/upload/$name$ext";
  move_uploaded_file($_FILES['img']['tmp_name'], $path);
  echo "upload/$name$ext";
}
?>