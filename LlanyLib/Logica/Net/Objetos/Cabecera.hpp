#pragma once
#ifndef CABECERA_OBJECT_NET_HPP_
#define CABECERA_OBJECT_NET_HPP_

#include "../../Math/Libs/MathTypes.h"

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
		}
	}
	namespace Net {
		namespace Objetos {
			class Cookie;
			class Cabecera 
			{
				protected:
					int responseCode = 200;
					Basic::Objetos::String* response;
					Basic::Objetos::String* acessControlAllowOrigin;
					Basic::Objetos::String* serverName;
					Basic::Objetos::String* contentType;
					Basic::Objetos::String* encodingType;
					ulong_t contentLength;
					Basic::Templates::Listas::LinkedList<Cookie>* cookies;
					Basic::Templates::Listas::LinkedList<Basic::Objetos::String*>* cabecerasExtras;
					Basic::Objetos::String* contenido;
					Basic::Objetos::String* upgrade;
					Basic::Objetos::String* connection;
					Basic::Objetos::Date* date;

				// Getters
				public int getResponseCode() { return responseCode; }
				public String getResponse() { return response; }
				public String getAcessControlAllowOrigin() { return acessControlAllowOrigin; }
				public String getServerName() { return serverName; }
				public String getContentType() { return contentType; }
				public List<Cookie> getCookies() { return this.cookies; }
				public int getContentLength() { return contentLength; }
				public List<String> getCabecerasExtras() { return cabecerasExtras; }
				public String getUpgrade() { return this.upgrade; }
				public String getConnection() { return this.connection; }

				// Setters
				public void setResponse(int responseCode, String reason) {
					if (reason != null)
						this.response = reason;
					this.responseCode = responseCode;
				}
				public void setResponseCode(int responseCode) { this.responseCode = responseCode; }
				public void setResponse(String response) {
					if (response != null)
						this.response = response;
				}
				public void setAcessControlAllowOrigin(String acessControlAllowOrigin) { this.acessControlAllowOrigin = acessControlAllowOrigin; }
				public void setServerName(String serverName) { this.serverName = serverName; }
				public void setContentType(String contentType)
				{
					if (contentType == null)
						this.contentType = "text/html";
					else
						this.contentType = contentType;
				}
				public void setContenido(String contenido) {
					if (contenido != null) {
						this.contentLength = contenido.length();
						this.contenido = contenido;
					}
				}
				public void setUpgrade(String upgrade) { this.upgrade = upgrade; }
				public void setConnection(String connection) { this.connection = connection; }
				public void setFechaExpiracion() {
					this.date = Date.from(Instant.now());
				}

				// Adders
				public void addCookie(Cookie cookie) { this.cookies.add(cookie); }
				public void addCookie(String key, String value) { this.cookies.add(new Cookie(key, value)); }

				public void addCabeceraExtra(String cabecera) { this.cabecerasExtras.add(cabecera); }

				// Remove
				//public void removeCookie(String cookieKey) { this.cookies.remove(cookieKey); }
				public void removeCabeceraExtra(String cabecera) { this.cabecerasExtras.remove(cabecera); }
				public void removeFechaExpiracion() {
					this.date = null;
				}


				public String toString() {
					StringBuffer resultado = new StringBuffer();

					resultado.append((String)"HTTP/1.1 ");
					resultado.append(this.responseCode + " " + this.response);
					resultado.append((String)"\r\n");

					if (this.date != null) {
						resultado.append((String)"Date: ");
						resultado.append(this.date.toString());
						resultado.append((String)"\r\n");
					}

					if (this.connection != null) {
						resultado.append((String)"Connection: ");
						resultado.append(this.connection);
						resultado.append((String)"\r\n");
					}

					if (this.upgrade != null) {
						resultado.append((String)"Upgrade: ");
						resultado.append(this.upgrade);
						resultado.append((String)"\r\n");
					}

					// Si se ha permitido el acceso desde algun sitio
					if (this.acessControlAllowOrigin != null) {
						resultado.append((String)"Access-Control-Allow-Origin: ");
						resultado.append(this.acessControlAllowOrigin);
						resultado.append((String)"\r\n");
					}

					// Si se ha puesto el nombre del servidor
					if (this.serverName != null) {
						resultado.append((String)"Server: ");
						resultado.append(this.serverName);
						resultado.append((String)"\r\n");
					}

					for (int i = 0; i < this.cookies.size(); i++) {
						resultado.append((String)"Set-Cookie: ");
						resultado.append(this.cookies.get(i).toString());
						resultado.append((String)"\r\n");
					}

					// Si hay contenido
					if (this.contentLength > 0) {
						resultado.append((String)"Content-Type: ");
						resultado.append(this.contentType);

						// Si se quiere que haya un tipo de encode
						if (this.encodingType != null) {
							resultado.append((String)"; charset=");
							resultado.append(this.encodingType);
						}
						resultado.append((String)"\r\n");
					}

					resultado.append((String)"Content-Length: ");
					resultado.append(this.contentLength);
					resultado.append((String)"\r\n");
					resultado.append((String)"Accept-Ranges: bytes\r\n");

					for (int i = 0; i < this.cabecerasExtras.size(); i++) {
						resultado.append(cabecerasExtras.get(i));
						resultado.append("\r\n");
					}

					resultado.append("\r\n");

					if (this.contenido != null)
						resultado.append(this.contenido);

					return resultado.toString();
				}
			}
		}
	}
}
#endif // !CABECERA_OBJECT_NET_HPP_
