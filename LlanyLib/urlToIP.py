from virus_total_apis import PublicApi

api = PublicApi("9937e4389b47e585c379961a9c932e29cd99486ca7fe739c56e2ca9b7c62afeb")

#response = api.get_url_report("http://www.google.com/")

#print(jsonify({"a": response}))

"""{
	"results": {
		"scan_id": "dd014af5ed6b38d9130e3f466f850e46d21b951199d53a18ef29ee9341614eaf-1603328400",
		"resource": "http://www.google.com/",
		"url": "http://www.google.com/",
		"response_code": 1,
		"scan_date": "2020-10-22 01:00:00",
		"permalink": "https://www.virustotal.com/gui/url/dd014af5ed6b38d9130e3f466f850e46d21b951199d53a18ef29ee9341614eaf/detection/u-dd014af5ed6b38d9130e3f466f850e46d21b951199d53a18ef29ee9341614eaf-1603328400",
		"verbose_msg": "Scan finished, scan information embedded in this object",
		"filescan_id": null,
		"positives": 0,
		"total": 80,
		"scans": {
			"Feodo Tracker": {
				"detected": false,
				"result": "clean site"
			},
			"CLEAN MX": {
				"detected": false,
				"result": "clean site"
			},
			"DNS8": {
				"detected": false,
				"result": "clean site"
			},
			"MalSilo": {
				"detected": false,
				"result": "clean site"
			},
			"NotMining": {
				"detected": false,
				"result": "unrated site"
			},
			"VX Vault": {
				"detected": false,
				"result": "clean site"
			},
			"securolytics": {
				"detected": false,
				"result": "clean site"
			},
			"Tencent": {
				"detected": false,
				"result": "clean site"
			},
			"MalwarePatrol": {
				"detected": false,
				"result": "clean site"
			},
			"MalBeacon": {
				"detected": false,
				"result": "clean site"
			},
			"Comodo Valkyrie Verdict": {
				"detected": false,
				"result": "clean site"
			},
			"PhishLabs": {
				"detected": false,
				"result": "unrated site"
			},
			"EmergingThreats": {
				"detected": false,
				"result": "clean site"
			},
			"Sangfor": {
				"detected": false,
				"result": "clean site"
			},
			"K7AntiVirus": {
				"detected": false,
				"result": "clean site"
			},
			"Spam404": {
				"detected": false,
				"result": "clean site"
			},
			"Virusdie External Site Scan": {
				"detected": false,
				"result": "clean site"
			},
			"Artists Against 419": {
				"detected": false,
				"result": "clean site"
			},
			"IPsum": {
				"detected": false,
				"result": "clean site"
			},
			"Cyren": {
				"detected": false,
				"result": "clean site"
			},
			"Quttera": {
				"detected": false,
				"result": "clean site"
			},
			"AegisLab WebGuard": {
				"detected": false,
				"result": "clean site"
			},
			"MalwareDomainList": {
				"detected": false,
				"result": "clean site",
				"detail": "http://www.malwaredomainlist.com/mdl.php?search=www.google.com"
			},
			"Lumu": {
				"detected": false,
				"result": "unrated site"
			},
			"zvelo": {
				"detected": false,
				"result": "clean site"
			},
			"Google Safebrowsing": {
				"detected": false,
				"result": "clean site"
			},
			"Kaspersky": {
				"detected": false,
				"result": "clean site"
			},
			"BitDefender": {
				"detected": false,
				"result": "clean site"
			},
			"GreenSnow": {
				"detected": false,
				"result": "clean site"
			},
			"G-Data": {
				"detected": false,
				"result": "clean site"
			},
			"OpenPhish": {
				"detected": false,
				"result": "clean site"
			},
			"Malware Domain Blocklist": {
				"detected": false,
				"result": "clean site"
			},
			"AutoShun": {
				"detected": false,
				"result": "unrated site"
			},
			"Trustwave": {
				"detected": false,
				"result": "clean site"
			},
			"Web Security Guard": {
				"detected": false,
				"result": "clean site"
			},
			"Cyan": {
				"detected": false,
				"result": "unrated site"
			},
			"CyRadar": {
				"detected": false,
				"result": "clean site"
			},
			"desenmascara.me": {
				"detected": false,
				"result": "clean site"
			},
			"ADMINUSLabs": {
				"detected": false,
				"result": "clean site"
			},
			"CINS Army": {
				"detected": false,
				"result": "clean site"
			},
			"Dr.Web": {
				"detected": false,
				"result": "clean site"
			},
			"AlienVault": {
				"detected": false,
				"result": "clean site"
			},
			"Emsisoft": {
				"detected": false,
				"result": "clean site"
			},
			"Spamhaus": {
				"detected": false,
				"result": "clean site"
			},
			"malwares.com URL checker": {
				"detected": false,
				"result": "clean site"
			},
			"Phishtank": {
				"detected": false,
				"result": "clean site"
			},
			"EonScope": {
				"detected": false,
				"result": "clean site"
			},
			"Malwared": {
				"detected": false,
				"result": "clean site"
			},
			"Avira": {
				"detected": false,
				"result": "clean site"
			},
			"Cisco Talos IP Blacklist": {
				"detected": false,
				"result": "clean site"
			},
			"CyberCrime": {
				"detected": false,
				"result": "clean site"
			},
			"Antiy-AVL": {
				"detected": false,
				"result": "clean site"
			},
			"Forcepoint ThreatSeeker": {
				"detected": false,
				"result": "clean site"
			},
			"SCUMWARE.org": {
				"detected": false,
				"result": "clean site"
			},
			"Certego": {
				"detected": false,
				"result": "clean site"
			},
			"URLhaus": {
				"detected": false,
				"result": "clean site"
			},
			"Yandex Safebrowsing": {
				"detected": false,
				"result": "clean site",
				"detail": "http://yandex.com/infected?l10n=en&url=http://www.google.com/"
			},
			"ESET": {
				"detected": false,
				"result": "clean site"
			},
			"Threatsourcing": {
				"detected": false,
				"result": "clean site"
			},
			"BlockList": {
				"detected": false,
				"result": "clean site"
			},
			"SecureBrain": {
				"detected": false,
				"result": "clean site"
			},
			"Nucleon": {
				"detected": false,
				"result": "clean site"
			},
			"PREBYTES": {
				"detected": false,
				"result": "clean site"
			},
			"Sophos": {
				"detected": false,
				"result": "clean site"
			},
			"Blueliv": {
				"detected": false,
				"result": "clean site"
			},
			"Hoplite Industries": {
				"detected": false,
				"result": "clean site"
			},
			"Netcraft": {
				"detected": false,
				"result": "unrated site"
			},
			"CRDF": {
				"detected": false,
				"result": "clean site"
			},
			"ThreatHive": {
				"detected": false,
				"result": "clean site"
			},
			"BADWARE.INFO": {
				"detected": false,
				"result": "clean site"
			},
			"FraudScore": {
				"detected": false,
				"result": "clean site"
			},
			"Quick Heal": {
				"detected": false,
				"result": "clean site"
			},
			"Rising": {
				"detected": false,
				"result": "clean site"
			},
			"StopBadware": {
				"detected": false,
				"result": "unrated site"
			},
			"Sucuri SiteCheck": {
				"detected": false,
				"result": "clean site"
			},
			"Fortinet": {
				"detected": false,
				"result": "clean site"
			},
			"StopForumSpam": {
				"detected": false,
				"result": "clean site"
			},
			"ZeroCERT": {
				"detected": false,
				"result": "clean site"
			},
			"Baidu-International": {
				"detected": false,
				"result": "clean site"
			},
			"Phishing Database": {
				"detected": false,
				"result": "clean site"
			}
		}
	},
	"response_code": 200
}"""

https://maps.google.com/maps?width=100%25&amp;height=600&amp;hl=es&amp;q=Les%20Rambles,%201%20Barcelona,%20Spain+(Mi%20nombre%20de%20egocios)&amp;t=&amp;z=14&amp;ie=UTF8&amp;iwloc=B&amp;output=embed

https://maps.google.com/maps?width=100%25&amp;height=600&amp;hl=es&amp;q=37.4043,-122.0748+(Mi%20nombre%20de%20egocios)&amp;t=&amp;z=14&amp;ie=UTF8&amp;iwloc=B&amp;output=embed

https://maps.google.com/maps?width=400&amp;height=400&amp;hl=es&amp;q=37.4043,-122.0748&amp;t=&amp;z=14&amp;ie=UTF8&amp;iwloc=B&amp;output=embed