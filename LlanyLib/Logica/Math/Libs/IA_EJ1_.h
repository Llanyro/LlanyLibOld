
typedef SOLUCION;
typedef ECUACION;
typedef SISTEMA_ECUACIONES;
typedef SOLUCIONES_GENERALES;

SISTEMA_ECUACIONES generarSistemaEcuaciones(ECUACION);
SOLUCIONES_GENERALES generarSolucionesGenerales(SISTEMA_ECUACIONES);
SOLUCION generarSolucionParticularRandom(SOLUCIONES_GENERALES);

SOLUCION resolverProblema(ECUACION e)
{
	// Transforma la ecuacion original en un sistema de equaciones a recolver
	SISTEMA_ECUACIONES s = generarSistemaEcuaciones(e);

	// Genera las soluciones generales de la ecuacion
	// Tanto las soluciones fijas, como las soluciones por rangos
	SOLUCIONES_GENERALES sol = generarSolucionesGenerales(s);

	// Devuelve una solucion especifica segun las soluciones generales dadas
	SOLUCION solucion = generarSolucionParticularRandom(sol);

	return solucion;
}