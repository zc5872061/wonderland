//<section name=gl>
#ifdef GL_ES
precision highp float;
#endif

varying vec4 v_color;
//</section>

//<section name=code>
void main (void)
{
	gl_FragColor = v_color;	
}