<div class="container center">
    <div class="row">
        <h5>Realizar Cadastro</h5>
    </div>
    <div class="row">
        <form class="col s12" id="register-form">
            <div class="row">
                <div class="input-field col s6">
                    <input id="name" type="text" class="validate">
                    <label for="name">Nome</label>
                </div>
            </div>
            <div class="row">
                <div class="input-field col s6">
                    <input id="email" type="email" class="validate">
                    <label for="email">Email</label>
                </div>
                <div class="input-field col s6">
                    <input id="password" type="password" class="validate">
                    <label for="password">Senha</label>
                </div>
                <input id="action" type="hidden" value="registerUser">
            </div>
            <div class="row">
                <button class="btn right">Cadastrar</button>
            </div>
        </form>
    </div>
</div>

<script>
    function parseFormData(form_id){
        data = {};
        $(form_id).find('input').each(function(obj){
            data[$(this).attr('id')] = $(this).val();
        });
        return data;
    }

    $(document).ready(function(){
        $("#register-form").submit(function(event){
            event.preventDefault();
            data = parseFormData("#register-form");
            $.get( "backend.php", {data}, function(data) {
                console.log(data);
            })
        });
    });
</script>