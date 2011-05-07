//<section name=gl>
#ifdef GL_ES
precision highp float;
#endif

varying vec2 v_textureCoordinate;
//</section>

//<section name=config>
uniform sampler2D u_textureSampler;
//</section>

//<section name=code>
void main()
{
	gl_FragColor = texture2D(u_textureSampler, v_textureCoordinate);
}
//</section>