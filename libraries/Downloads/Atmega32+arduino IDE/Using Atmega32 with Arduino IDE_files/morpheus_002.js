// Sonobi Morpheus
var sbi_morpheus = {
	c: 0,
	l: 0,
	d: false,
	tor: false,
	loc: 'neo.go.sonobi.com',
	td: 1000,
	useBug: false,
	whiteRabbit: (function(oatmealCookie) {}),
	whiteRabbitEnabled: false,
	registration: {},
	synchronous: false,
	old_refresh: function() { try { /*console.log('MORPHEUS OR'); */ setTimeout((function() { googletag.pubads().refresh(); }), 1500); } catch(e) { /*console.log('MORPHEUS OR ERROR: ' + e);*/ } },
	enableSynchronous: function() {sbi_morpheus.synchronous = true;},
	jackIn: function(bug) {
		if (typeof(bug) == 'undefined') bug = false;

		sbi_morpheus.useBug = bug;

		if (!sbi_morpheus.useBug) {
			sbi_morpheus.uc();
		} else {
			setTimeout(sbi_morpheus.uc, 1500);
		}
	},
	follow: function(oatmealCookie) {
		try {
			sbi_morpheus.whiteRabbit(oatmealCookie);
		} catch (e) {}
	},
	register: function(dfpid, sid, async) {
		if (typeof(async) == 'undefined') async = true;

		if (sbi_morpheus.useBug) {
			sbi_morpheus.registration[dfpid] = sid;
		} else {
			sbi_morpheus._launch('//'+sbi_morpheus.loc+'/morpheus.js?did='+dfpid+'&sid='+sid, async);
		}

		sbi_morpheus.c += 1;
	},
	callOperator: function(whiteRabbit, td) {
		if (sbi_morpheus.useBug) {
			//console.log('MORPHEUS CO(); CALLED');
			sbi_morpheus._launch(
				'//'+sbi_morpheus.loc+'/morpheus.js?key_maker='+
				JSON.stringify(sbi_morpheus.registration)+
				(typeof(whiteRabbit) != 'undefined' ? '&whiteRabbit' : ''
			), !sbi_morpheus.synchronous);
			if(sbi_morpheus.synchronous) return;
		}		
		if (typeof(whiteRabbit) != 'undefined') {
			sbi_morpheus.whiteRabbit = whiteRabbit;
			sbi_morpheus.whiteRabbitEnabled = true;
		} else {
			sbi_morpheus.whiteRabbitEnabled = false;
			sbi_morpheus.tor = true;

			sbi_morpheus.r((function() {
				if (typeof(td) == 'undefined') var td = sbi_morpheus.td;
				var st = new Date().getTime();
				var f = (function() {
					//console.log('MORPHEUS CO(); F(); CALLED');
					try {
						var now = new Date().getTime();

						if (now >= st + td || (sbi_morpheus.l >= sbi_morpheus.c)) {
							googletag.cmd.push(function() {
								for (var dfpid in sbi_morpheus.registration) break;
								for (var slots in googletag.slot_manager_instance) {
									if(dfpid in googletag.slot_manager_instance[slots]) break;
								}
								for (var id in googletag.slot_manager_instance[slots]) {
									//console.log('MORPHEUS DISPLAY: ' + id);
									googletag.display(id);
								}

								if(!sbi_morpheus.d) {
									//console.log('MORPHEUS OR(); SETTIMEOUT');
									// setTimeout(googletag.pubads().refresh, 300);
									setTimeout(sbi_morpheus.old_refresh, 300);
									// sbi_morpheus.old_refresh();
								}
								sbi_morpheus.d = true;
							});
							return;
						}
					} catch (e) {
						//console.log('MORPHEUS COR ERROR: ' + e);

						if(!sbi_morpheus.d) sbi_morpheus.old_refresh();
						sbi_morpheus.d = true;
					}

					//console.log('MORPHEUS CO(); F(); SETTIMEOUT');
					setTimeout(f, 2);
				});

				//console.log('MORPHEUS CO(); F();');
				f();
			}));
		}
	},
	uc: function() {
		sbi_morpheus._launch('//sync.go.sonobi.com/uc.js');
	},
	r: function(callback) {
		var f = (function() {
			try {
				if (typeof(googletag) != 'undefined' && typeof(googletag.cmd) != 'undefined') {
					googletag.cmd.push(function() {
					   googletag.pubads().disableInitialLoad();
					});

					if (typeof(callback) != 'undefined') callback();

					return;
				}
			} catch (e) {
				//console.log('MORPHEUS R ERROR: ' + e);
				if(!sbi_morpheus.d) sbi_morpheus.old_refresh();
				sbi_morpheus.d = true;
			}			
			setTimeout(f, 2);
		});
		f();
	},
	_launch: function(src, async) {
		if (typeof(async) == 'undefined') async = true;
		if (async) {
			try {	
				var sb = document.createElement('script');
				sb.type = 'text/javascript';
				sb.async = true;
				sb.src = src;
				var sc = document.getElementsByTagName('script')[0];
				sc.parentNode.insertBefore(sb, sc);
			} catch(e) {}
		} else {
			document.write("<scr" + "ipt type='text/javascript' src='"+src+"'></scr" + "ipt>");
		}
	}
};

(function() {
	var bug = true;

	var sel = document.getElementsByTagName('script');

	for (var i = 0; i < sel.length; i += 1) {		
		if (sel[i].src.indexOf('morpheus.js') > -1) {
			if (sel[i].src.indexOf('nobug') > -1) bug = false;
			break;
		}
	}

	sbi_morpheus.jackIn(bug);

	var get_native = (function(native) {
		var iframe = document.createElement('iframe');
		document.body.appendChild(iframe);
		var retrieved = iframe.contentWindow[native];
		document.body.removeChild(iframe);
		return retrieved;
	});
		
	var f = (function() {
		try {
			if (typeof(googletag) != 'undefined' && typeof(googletag.cmd) != 'undefined' && typeof(googletag.service_manager_instance) != 'undefined') {
				var pubads = googletag.service_manager_instance;
				for (var services in googletag.slot_manager_instance) if('publisher_ads' in pubads[services]) break;
				if('publisher_ads' in pubads[services]){
					pubads = pubads[services].publisher_ads;
				} else {
					return;
				}

				var refresh_supported = true;

				if (pubads.refresh.bind.toString().indexOf('[native code]') > -1) {
					sbi_morpheus.old_refresh = pubads.refresh.bind(pubads);
				} else {
					if (typeof('Prototype') != 'undefined') {
						var version = Prototype.Version.split('.');
						version = parseFloat(version[0] + '.' + version[1]);

						if (version >= 1.8) {
							sbi_morpheus.old_refresh = pubads.refresh.bind(pubads);	
						} else {
							//console.log('MORPHEUS REFRESH NOT SUPPORTED WITH PROTOTYPE VERSION: ' + Prototype.Version);
							refresh_supported = false;
						}
					} 
				}

				var btd = new Date().getTime();
				
				sbi_morpheus.refresh = function(td) {
					//console.log('MORPHEUS REFRESH(); CALLED: TD = ' + td);
					var now = new Date().getTime();

					if (typeof(td) == 'undefined') {
						var td = (sbi_morpheus.td + now);

						if (!sbi_morpheus.tor) {
							//console.log('MORPHEUS REFRESH(); LAUNCH CALLED');
							sbi_morpheus.l = 0;
							sbi_morpheus._launch(
								'//'+sbi_morpheus.loc+'/morpheus.js?key_maker='+
								JSON.stringify(sbi_morpheus.registration), 
								!sbi_morpheus.synchronous
							);
						}
					}
					
					if ((typeof(td) != 'undefined' && now >= td) || (sbi_morpheus.l >= sbi_morpheus.c && now >= btd + 300)) {
						//console.log('MORPHEUS SETUP F(); OR CALLED');
						sbi_morpheus.old_refresh();
						sbi_morpheus.d = true;
						sbi_morpheus.tor = false;
						return;
					}
					//console.log('MORPHEUS SETUP F(); REFRESH(); SETTIMEOUT');
					setTimeout(function() {sbi_morpheus.refresh(td);}, 2);
				};

				if (refresh_supported) {
					if (sbi_morpheus.useBug && !sbi_morpheus.whiteRabbitEnabled) pubads.refresh = sbi_morpheus.refresh;
				} else {
//					sbi_morpheus.refresh();
//					sbi_morpheus.old_refresh();
				}

				return;
			}
		} catch (e) {
			//console.log('MORPHEUS F(); ERROR: ' + e);
		}			
		setTimeout(f, 2);
	});
	f();
})();