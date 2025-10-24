function likes(nro) {
  if (nro < 1000) {
    return nro.toString();
  } else if (nro >= 1000 && nro < 1000000) {
    return Math.floor(nro / 1000) + "K";
  } else {
    return Math.floor(nro / 1000000) + "M";
  }
}

// código de prueba
console.log(likes(983)); // "983"
console.log(likes(1900)); // "1K"
console.log(likes(54000)); // "54K"
console.log(likes(120800)); // "120K"
console.log(likes(25222444)); // "25M"
