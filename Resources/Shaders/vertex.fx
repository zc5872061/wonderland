//<section name=engine>
uniform mat4 u_mvpMatrix; // <var map=modelviewprojection/>
uniform mat4 u_mMatrix; // <var map=model/>
uniform vec3 u_cameraPos; // <var map=cameraposition/>
uniform vec3 u_lightDirection; // <var map=lightdirection/>
//</section>

//<section name=config>
uniform vec4 u_diffuseColor; 
uniform vec4 u_ambientColor; 
uniform float u_fresnelAmount; 
//</section>

//<section name=input>
attribute vec4 a_position; // <var map=position/>
attribute vec3 a_normal; // <var map=normal/>
//attribute vec2 a_uv; // <var map=uv/>
//</section>

//<section name=gl>
varying vec3 v_normal;
varying vec3 v_position;
//</section>

//<section name=code>
void main()
{
	gl_Position = u_mvpMatrix * a_position;
    
    v_normal = a_normal;
    v_position = vec3(u_mMatrix * a_position);
}       
//</section>                                         