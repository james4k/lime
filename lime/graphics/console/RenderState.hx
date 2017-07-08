package lime.graphics.console;


@:enum abstract RasterizerState(Int) {

	var CULLNONE_WIREFRAME  = 0;
	var CULLCW_WIREFRAME    = 1;
	var CULLCCW_WIREFRAME   = 2;
	var CULLNONE_SOLID      = 3;
	var CULLCW_SOLID        = 4;
	var CULLCCW_SOLID       = 5;

}


@:enum abstract DepthStencilState(Int) {

	var DEPTHTESTOFF_DEPTHWRITEOFF_STENCILOFF           = 0;
	var DEPTHTESTON_DEPTHWRITEON_DEPTHLESS_STENCILOFF   = 1;
	var DEPTHTESTON_DEPTHWRITEOFF_DEPTHLESS_STENCILOFF  = 2;
	var DEPTHTESTOFF_DEPTHWRITEON_DEPTHLESS_STENCILOFF  = 3;
	var DEPTHTESTON_DEPTHWRITEON_DEPTHALWAYS_STENCILOFF = 4;

}


@:enum abstract BlendState(Int) {

	var NONE_A											= 0;
	var NONE_RGB                                        = 1;
	var NONE_RGBA                                       = 2;
	var ONE_INVSRCALPHA_ONE_ZERO_RGB                    = 3;
	var SRCALPHA_INVSRCALPHA_ONE_ZERO_RGB               = 4;
	var SRCALPHA_INVSRCALPHA_ONE_ZERO_RGBA              = 5;
	var SRCALPHA_INVSRCALPHA_SRCALPHA_INVSRCALPHA_RGBA  = 6;
	var SRCALPHA_INVSRCALPHA_INVDESTALPHA_ONE_RGBA      = 7;
	var ZERO_INVSRCCOLOR_ONE_ZERO_RGBA                  = 8;
	var ZERO_SRCCOLOR_ONE_ZERO_RGBA                     = 9;
	var SRCALPHA_ONE_ONE_ZERO_RGB                       = 10;
	var SRCALPHA_ONE_ONE_ZERO_RGBA                      = 11;
	var SRCALPHA_ONE_ONE_ONE_RGBA                       = 12;
	var DESTCOLOR_INVSRCALPHA_ONE_ZERO_RGB              = 13;
	var DESTCOLOR_INVSRCALPHA_ONE_ZERO_RGBA             = 14;
	var DESTCOLOR_SRCCOLOR_ONE_ZERO_RGB                 = 15;
	var DESTCOLOR_SRCCOLOR_ONE_ZERO_RGBA                = 16;
	var ONE_ONE_ONE_ZERO_RGB                            = 17;
	var ONE_ONE_ONE_ZERO_RGBA                           = 18;
	var ONE_ONE_ONE_ONE_RGB                             = 19;
	var ONE_ONE_ONE_ONE_RGBA                            = 20;
	var ONE_ZERO_ONE_ZERO_RGB                           = 21;
	var ONE_ZERO_ONE_ZERO_RGBA                          = 22;
	var ZERO_ONE_ZERO_ONE                               = 23;

}
