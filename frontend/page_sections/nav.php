
<nav role="navigation" class="blue darken-3">
    <div class="nav-wrapper">
        <a id="logo-container" href="/" class="brand-logo white-text">
            Evendas
        </a>
        <ul class="right hide-on-med-and-down" hidden>
            <li><a href="/app/login" class="white-text">Área do Cliente</a></li>
        </ul>
        <ul class="sidenav sidenav-fixed invesible-top" id="mobile-nav">
            <div id="logged_nav" hidden>
                <li><div class="divider"></div></li>
                <li><a class="subheader" id="logged_nav_name"></a></li>
                <li><a class="waves-effect sidenav-link" action="logged/dashboard.html">Dashboard</a></li>
                <li><a class="waves-effect sidenav-link" action="logged/profile.html">Perfil</a></li>
                <li><a class="waves-effect sidenav-link" action="logged/announce.html">Anunciar</a></li>
                <li><a class="waves-effect sidenav-link" action="logout.html">Sair</a></li>
            </div>
            <div id="unlogged_nav" hidden>
                <li><a class="subheader">Novos Usuários</a></li>
                <li><a class="waves-effect sidenav-link" action="register.html">Fazer Cadastro</a></li>
                <li><a class="waves-effect sidenav-link" action="login.html">Fazer Login</a></li>
            </div>
            <li><div class="divider"></div></li>
            <li><a class="subheader">Produtos</a></li>
            <li><a class="waves-effect sidenav-link" action="products/categories.html">Ver categorias</a></li>
        </ul>
        <a href="#" data-target="mobile-nav" class="sidenav-trigger"><i class="material-icons white-text">menu</i></a>
    </div>
</nav>

<script>
  $(document).ready(function(){
    $('.sidenav').sidenav();
  });
</script>