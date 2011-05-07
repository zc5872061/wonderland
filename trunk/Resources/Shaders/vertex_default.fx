//<section name=engine>
uniform mat4 u_mvpMatrix; //<var map=modelviewprojection/>
//</section>

//<section name=input>
attribute vec4 a_position;
//</section>

//<section name=code>
void main()
{
	gl_Position = u_mvpMatrix * a_position;
}                                                
//</section>