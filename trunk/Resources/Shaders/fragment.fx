#ifdef GL_ES
precision highp float;
#endif
//<section name=engine>
uniform vec3 u_lightDirection; // <var map=lightdirection/>
uniform vec3 u_cameraPos; // <var map=cameraposition/>
//</section>

//<section name=config>
uniform vec4 u_diffuseColor; 
uniform vec4 u_ambientColor; 
uniform float u_fresnelAmount; 
//</section>

//<section name=gl>
varying vec3 v_normal; 
varying vec3 v_position;
//</section>

//<section name=code>

float getDiffuseTerm(void)
{
    return clamp(dot(-v_normal, u_lightDirection), 0.0, 1.0);
}

float getFresnelTerm(void)
{
    return 1.0 - abs(dot(normalize(u_cameraPos-v_position), -v_normal));
}

float getReflectionAmount(void)
{
    vec3 reflected = normalize(reflect(u_lightDirection, v_normal));
    return pow(max(0.0, dot(normalize(u_cameraPos-v_position), reflected)), 10.0); 
}

void main (void)
{
    float diffuseTerm = getDiffuseTerm();
    float fresnelTerm = getFresnelTerm();
    
    vec4 diffuseColor = clamp(u_ambientColor*u_diffuseColor + diffuseTerm*u_diffuseColor, 0.0, 1.0);
    vec4 reflectionColor = vec4(0.82, 0.85, 0.85, 1.0);
    
    float spec = getReflectionAmount();
    
    gl_FragColor = min(mix(diffuseColor, reflectionColor, u_fresnelAmount*fresnelTerm) + vec4(spec, spec, spec, 1.0), vec4(1,1,1,1));
}

//</section>