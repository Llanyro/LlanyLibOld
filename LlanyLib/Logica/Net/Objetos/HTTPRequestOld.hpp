#pragma once
#ifndef HTTP_REQUEST_OLD_OBJECT_NET_HPP_
#define HTTP_REQUEST_OLD_OBJECT_NET_HPP_

namespace LlanyLib {
	namespace Basic {
		namespace Objetos {
			class String;
			class Date;
		}
		namespace Templates {
			namespace Listas {
				template<class T>
				class LinkedList;
			}
			namespace Diccionarios {
				template<class T1, class T2>
				class DictionaryLinkedList;
			}
		}
	}
	namespace Net {
		namespace Enum {
			enum class ResponseProcess;
		}
		namespace Objetos {
			class HTTPRequestOld
			{
				protected:
					Basic::Objetos::String* peticion;	// GET,POST,OPTIONS
					Basic::Objetos::String* root;		// "/", "/index", ...
					Basic::Objetos::String* version;	// HTTP/1.1
					Basic::Objetos::String* host;		// localhost:8080
					Basic::Objetos::String* connection;	// keep-alive
					bool upgrade_insecure_requests;		// 0 o 1

					// text/html, application/xhtml+xml, application/xml; q=0.9, image/avif, image/webp, image/apng, */*;q=0.8,application/signed-exchange;v=b3;q=0.9
					Basic::Templates::Listas::LinkedList<Basic::Objetos::String*>* typesAccepted;
					Basic::Templates::Listas::LinkedList<Basic::Objetos::String*>* encodingsAccepted;
					Basic::Objetos::String* userAgent;	// Mozilla/5.0 (Windows NT 10.0; Win64; x64)
					Basic::Objetos::String* contenido;	// Contenido del mensaje
					Basic::Templates::Diccionarios::DictionaryLinkedList<
						Basic::Objetos::String*,
						Basic::Objetos::String*>* other;
				protected:
					void processHTTPRequest(Basic::Objetos::String* all, const Enum::ResponseProcess& processType);
					void processPetition(Basic::Objetos::String* all);
					void processPostContent(Basic::Objetos::String* all);
					void processFast(Basic::Objetos::String* all);
					void processSuperSlow(Basic::Objetos::String* all);
				public:
					HTTPRequestOld(Basic::Objetos::String* all);
					HTTPRequestOld(Basic::Objetos::String* all, const Enum::ResponseProcess& processType);
					~HTTPRequestOld();
					#pragma region Getters
					const Basic::Objetos::String* getPeticion() const;
					const Basic::Objetos::String* getRoot() const;
					const Basic::Objetos::String* getVersion() const;
					const Basic::Objetos::String* getHost() const;
					const Basic::Objetos::String* getConnection() const;
					bool getUpgradeInsecureRequests() const;
					size_t getNumAcceptTypes() const;
					const Basic::Objetos::String* getAcceptedType(const size_t& pos) const;
					const Basic::Objetos::String* getUserAgent() const;
					size_t getNumOther() const;
					const Basic::Objetos::String* getOtherStartWithSimilar(char const* const str) const;
					const Basic::Objetos::String* getContenido() const;
					#pragma endregion
					Basic::Objetos::String* toString() const;
			};
		}
	}
}
#endif // !HTTP_REQUEST_OBJECT_NET_HPP_

//POST /?test=tomate HTTP / 1.1
//Host : localhost : 9090
//User - Agent : python - requests / 2.24.0
//Accept - Encoding : gzip, deflate
//Accept : */*
//Connection: keep-alive
//Content-Length: 0
//
//Bytes sent: 233

//GET / ? test = tomate HTTP / 1.1
//Host : localhost : 9090
//User - Agent : python - requests / 2.24.0
//Accept - Encoding : gzip, deflate
//Accept : */*
//Connection: keep-alive
//
//Bytes sent: 233

/// GET /API/ HTTP/1.1
/// Host: localhost:8080
/// Accept : text / html, application / xhtml + xml, application / xml; q = 0.9, image / avif, image / webp, image / apng, */*;q=0.8,application/signed-exchange;v=b3;q=0.9
/// Upgrade-Insecure-Requests: 1
/// User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/85.0.4183.121 Safari/537.36 OPR/71.0.3770.228
/// 
/// HTTP/1.1 200 YAY it works!!!
/// Accept-Ranges: bytes
/// Access-Control-Allow-Origin: *
/// Content-Length: 19
/// Content-Type: text/html; charset=utf-8
/// Date: Sun Oct 11 23:49:08 CEST 2020
/// Server: Server Interfaz for PAWR

///Accept: text / html, application / xhtml xml, application / xml; q = 0.9, image / avif, image / webp, image / apng, */*;q=0.8,application/signed-exchange;v=b3;q=0.9
///Connection: keep-alive
///User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/85.0.4183.121 Safari/537.36 OPR/71.0.3770.228
///Sec-Fetch-Site: none
///Sec-Fetch-Dest: document
///Host: localhost:8080
///Accept-Encoding: gzip, deflate, br
///Sec-Fetch-Mode: navigate
///Parametros Peticion: /API/
///Peticion: GET
///Cache-Control: max-age=0
///Version: HTTP/1.1
///Upgrade-Insecure-Requests: 1
///Sec-Fetch-User: ?1
///Accept-Language: es-ES,es;q=0.9
///
///
///HTTP/1.1 200 YAY it works!!!
///Date: Sun Oct 11 23:48:32 CEST 2020
///Access-Control-Allow-Origin: *
///Server: Server Interfaz for PAWR
///Content-Type: text/html; charset=utf-8
///Content-Length: 19
///Accept-Ranges: bytes
///
///Server Interface V1
///Accept: text/html,application/xhtml xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*; q = 0.8, application / signed - exchange; v = b3; q = 0.9
///Connection: keep - alive
///User - Agent : Mozilla / 5.0 (Windows NT 10.0; Win64; x64) AppleWebKit / 537.36 (KHTML, like Gecko) Chrome / 85.0.4183.121 Safari / 537.36 OPR / 71.0.3770.228
///Sec - Fetch - Site : none
///Sec - Fetch - Dest : document
///Host : localhost:8080
///Accept - Encoding : gzip, deflate, br
///Sec - Fetch - Mode : navigate
///Parametros Peticion : / API /
///Peticion : GET
///Version : HTTP / 1.1
///Upgrade - Insecure - Requests : 1
///Accept - Language : es - ES, es; q = 0.9
///
///
///HTTP / 1.1 200 YAY it works!!!
///Date: Sun Oct 11 23 : 48 : 37 CEST 2020
///Access - Control - Allow - Origin : *
///Server : Server Interfaz for PAWR
///Content - Type : text / html; charset = utf - 8
///Content - Length: 19
///Accept - Ranges : bytes
///
///Server Interface V1
///Accept : text / html, application / xhtml xml, application / xml; q = 0.9, image / avif, image / webp, image / apng, */*;q=0.8,application/signed-exchange;v=b3;q=0.9
///Connection: keep-alive
///User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/85.0.4183.121 Safari/537.36 OPR/71.0.3770.228
///Sec-Fetch-Site: none
///Sec-Fetch-Dest: document
///Host: localhost:8080
///Accept-Encoding: gzip, deflate, br
///Sec-Fetch-Mode: navigate
///Parametros Peticion: /API/
///Peticion: GET
///Cache-Control: max-age=0
///Version: HTTP/1.1
///Upgrade-Insecure-Requests: 1
///Sec-Fetch-User: ?1
///Accept-Language: es-ES,es;q=0.9
///
///
///HTTP/1.1 200 YAY it works!!!
///Date: Sun Oct 11 23:49:08 CEST 2020
///Access-Control-Allow-Origin: *
///Server: Server Interfaz for PAWR
///Content-Type: text/html; charset=utf-8
///Content-Length: 19
///Accept-Ranges: bytes
///
///Server Interface V1