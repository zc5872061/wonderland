//<section name=engine>
uniform mat4 u_mvpMatrix; // <var map=modelviewprojection/>
//uniform mat4 u_mMatrix; // <var map=model/>
// </section>

// <section name=input>
attribute vec4 a_position; // <var map=position/>
attribute vec2 a_uv; // <var map=uv/>
// </section>

// <section name=gl>
varying vec2 v_textureCoordinate;
// </section>

// <section name=code>
void main()
{
	v_textureCoordinate = a_uv;
	gl_Position = u_mvpMatrix * a_position;	
}                                            