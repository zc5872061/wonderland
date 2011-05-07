//<section name=engine>
uniform mat4 u_mvpMatrix; //<var map=modelviewprojection/>
uniform vec4 u_diffuseColor; //<var map=diffuse/>
//</section>

//<section name=input>
attribute vec4 a_position;
attribute vec3 a_normal;
//</section>

//<section name=config>
uniform float u_lineWidth;
//</section>


//<section name=gl>
varying vec4 v_color;
//</section>


//<section name=code>
void main()
{
	v_color = u_diffuseColor;
	vec4 temp = a_position;
	temp.x += a_normal.x * u_lineWidth;
	temp.y += a_normal.y * u_lineWidth;
	temp.z += a_normal.z * u_lineWidth;
	gl_Position = u_mvpMatrix * temp;
}                                                
