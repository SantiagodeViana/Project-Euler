//Función usada en Project Euler #36

bool isPalindrome(string n){ //Función para determinar si una cadena de caracteres es palíndroma. 
	if (n == string(n.rbegin(), n.rend())) return true; //Devuelve true de serlo
	return false; //False de lo contrario
}
