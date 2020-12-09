
<nav role="navigation" class="blue darken-3">
    <div class="nav-wrapper">
        <a id="logo-container" href="/" class="brand-logo white-text">
            Evendas
        </a>
        <ul class="right hide-on-med-and-down" hidden>
            <li><a href="/app/login" class="white-text">Área do Cliente</a></li>
        </ul>
        <ul class="sidenav sidenav-fixed invesible-top" id="mobile-nav">
            <li><a class="subheader">Usuários</a></li>
            <li><a class="waves-effect" href="#!">Fazer Cadastro</a></li>
            <li><a class="waves-effect" href="#!">Fazer Login</a></li>
            <li><div class="divider"></div></li>
            <li><a class="subheader">Produtos</a></li>
            <li><a class="waves-effect" href="#!">Ver categorias</a></li>
            <li><a class="waves-effect" href="#!"></a></li>
        </ul>
        <a href="#" data-target="mobile-nav" class="sidenav-trigger"><i class="material-icons white-text">menu</i></a>
    </div>
</nav>

<script>
  $(document).ready(function(){
    $('.sidenav').sidenav();
  });
</script>