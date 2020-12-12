var Evendas = {};

Evendas.loadPage = function(path) {
    if (path.startsWith("logged/") && Evendas.loggedUser == null) {
        alert("Para acessar essa funcionalidade, é preciso estar logado.");
        Evendas.loadPage("login.html");
    } else $("main").load("pages/" + path);
};

Evendas.getBackend = function(data, callback){
    $.get("backend.php", data, function(data) {
        data = JSON.parse(data);
        if (data.status == "OK") {
            callback(true, data);
        } else {
            callback(false, data.error);
        }
    });
};

Evendas.parseFormData = function(form_id){
    data = {};
    $(form_id).find('input').each(function(obj){
        data[$(this).attr('id')] = $(this).val();
    });
    return data;
};

Evendas.prepareForm = function(form_id, callback){
    $(form_id).submit(function(event){
        event.preventDefault();
        data = Evendas.parseFormData(form_id);
        Evendas.getBackend(data, callback);
    });
};

Evendas.verifySession = function() {
    Evendas.getBackend({action: "verifySession"}, function(success, response){
        if (success && response.valid_session) {
            Evendas.loggedUser = response.user;
            $("#logged_nav").show();
            $("#logged_nav_name").text(Evendas.loggedUser.name);
            $("#unlogged_nav").hide();
            Evendas.loadPage("logged/dashboard.html");
            Evendas.getBackend({action: "getUserData"}, function(success, response) {
                if (success) {
                    Evendas.userData = response.user_data;
                    console.log(response);
                }
            });
        } else {
            Evendas.loggedUser = null;
            $("#unlogged_nav").show();
            $("#logged_nav").hide();
            Evendas.loadPage("login.html");
        }
    });
};

Evendas.endSession = function() {
    Evendas.getBackend({action: "endSession"}, function(success, response){
        window.location.href = "/";
    });
};

$(document).ready(function() {
    $(".sidenav-link").click(function(e) {
        e.preventDefault();
        Evendas.loadPage($(this).attr("action"));
    });
});