En la libreria se encontraran dos tipos de "plantillas", cada tipo tiene su significado:
	Por un lado las plantillas guardadas en la carpeta plantillas son clases que que adaptan al tipo indicado en el "template<>"
	Por otro lado las otras plantillas son clases abstractas/interfaces que en si no tienen uso pero que el heredar dan cuerpo al objeto en cuestion


	define de un objeto
#pragma once
#ifndef CLASS_NAME_OBJECTTYPE_LIBNAME_HPP_
#define CLASS_NAME_OBJECTTYPE_LIBNAME_HPP_

namespace LIBNAME {
	namespace OBJECTTYPE {
		class CLASS_NAME {
			...
		};
	}
}
#endif // !CLASS_NAME_OBJECTTYPE_LIBNAME_HPP_
