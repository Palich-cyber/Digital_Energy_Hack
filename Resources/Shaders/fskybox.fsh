uniform sampler2D u_texture;
//uniform samplerCube u_texture;
//varying highp vec3 texture_;
varying highp vec2 texture;


void main()
{
    //gl_FragColor = texture(u_texture, vec3(texture, 1.0));
    gl_FragColor = texture2D(u_texture, texture);
}
