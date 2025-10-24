function bmi(peso, altura) {
  const BMI = peso / (altura * altura);
  if (BMI < 18.5) {
    return console.log("Bajo de peso");
  }
  if (BMI >= 18.5 && BMI <= 24.9) {
    return console.log("normal");
  }
  if (BMI >= 25 && BMI <= 29.9) {
    return console.log("sobrepeso");
  } else {
    return console.log("obeso");
  }
}

// código de prueba
console.log(bmi(65, 1.8)); // "Normal"
console.log(bmi(72, 1.6)); // "Sobrepeso"
console.log(bmi(52, 1.75)); //  "Bajo de peso"
console.log(bmi(135, 1.7)); // "Obeso"
