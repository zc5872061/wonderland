#ifdef GL_ES
precision highp float;
#endif

// <section name=config>
uniform float u_enabled;
uniform sampler2D u_textureSampler;
// </section>

// <section name=gl>
varying vec2 v_textureCoordinate;
// </section>

// <section name=code>
void main (void)
{
	vec4 tempColor = texture2D(u_textureSampler, v_textureCoordinate);
//	if(u_enabled < 0.5)
//	{
//		float value = (tempColor.x + tempColor.y + tempColor.z) / 3.0;
//		tempColor.x = value;
//		tempColor.y = value;
//		tempColor.z = value;
//	}
	gl_FragColor = tempColor;
	//gl_FragColor = vec4(0.2,0.2,1,1); // for simulator
}