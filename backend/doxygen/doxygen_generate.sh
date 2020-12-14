rm -rf html/
rm -rf latex/

doxygen doxygen_config

# Gerando servidor web temporário
cd html
python3 -m http.server 8080
