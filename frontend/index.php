<html>
<?php
    $page_title = "Evendas - Bem Vindo";
    include "page_sections/head.php";
    echo "<body>";
    include "page_sections/nav.php";
    echo "<main><div class='center'>Carregando...</div></main>";
    include "page_sections/footer.php";
    echo "</body>";
?>
    <script>
        $(document).ready(function() {
            Evendas.verifySession();
        });
    </script>
</html>