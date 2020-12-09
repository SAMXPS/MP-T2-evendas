var Evendas = {};

Evendas.loadPage = function(path) {
    $("main").load("pages/" + path);
}

Evendas.getBackend = function(data, callback){
    $.get( "backend.php", data, function(data) {
        data = JSON.parse(data);
        if (data.status == "OK") {
            callback(true, data);
        } else {
            callback(false, data.error);
        }
    });
}