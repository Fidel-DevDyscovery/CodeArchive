print("ingrese la operacion a realizar(+, -, * , /): ")
signo = input()

numero1=98.34
numero2=10.23

resultado=None
if signo == '+':
    resultado=numero1+numero2
    print("el resultado de la suma es: ",resultado)
elif signo == '-':
    resultado=numero1-numero2
    print("el resultado de la resta es: ",resultado)
elif signo == '*':
    resultado=numero1*numero2
    print("el resultado de la multiplicacion es: ",resultado)
elif signo == '/':
    resultado=numero1/+numero2
    print("el resultado de la divicion es: ",resultado)
else:
    print("valor incorrecto, vuelva a ingresar un valor correcto")