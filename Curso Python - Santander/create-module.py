import mi_modulo
import mod_operaciones
import mod_funcionalidades

mi_modulo.saludo("gaston")
res = mi_modulo.product(3, 5)
print(res)

print(mod_operaciones.dividir(1, 3))

mod_funcionalidades.imprimir_mensaje("Modulo importado")

var = mod_funcionalidades.solicitar_datos()
print(var)