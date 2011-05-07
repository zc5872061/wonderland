//<section name=engine>
uniform mat4 u_mvpMatrix; // <var map=modelviewprojection/>
//</section>

//<section name=input>
attribute vec4 a_position; // <var map=position/>
//attribute vec3 a_normal; // <var map=normal/>
attribute vec2 a_uv; // <var map=uv/>
//</section>

//<section name=gl>
varying vec2 v_textureCoordinate;
//</section>

//<section name=code>
void main()
{
	gl_Position = u_mvpMatrix * a_position;
	v_textureCoordinate = a_uv;
}
//</section>