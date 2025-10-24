function contrasenaValida(contraseña) {
  if (contraseña === "2Fj(jjbFsuj" || contraseña === "eoZiugBf&g9") {
    return true;
  } else {
    return false;
  }
}

// escribe tu respuesta acá

// código de prueba
console.log(contrasenaValida("2Fj(jjbFsuj")); // true
console.log(contrasenaValida("eoZiugBf&g9")); // true
console.log(contrasenaValida("hola")); // false
console.log(contrasenaValida("")); // false

/////////////////////////////////////////// validacion mejor

function contrasenaValida2(contraseña) {
  const contraseñas = ["2Fj(jjbFsuj", "eoZiugBf&g9"];
  if (!contraseña) {
    return false;
  }
  return contraseñas.includes(contraseña);
}
