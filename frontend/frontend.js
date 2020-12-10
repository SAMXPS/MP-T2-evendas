var Evendas = {};

Evendas.loadPage = function(path) {
    $("main").load("pages/" + path);
};

Evendas.getBackend = function(data, callback){
    console.log(data);
    $.get("backend.php", data, function(data) {
        console.log(data);
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

$(document).ready(function() {
    $(".sidenav-link").click(function(e) {
        e.preventDefault();
        Evendas.loadPage($(this).attr("action"));
    });
});