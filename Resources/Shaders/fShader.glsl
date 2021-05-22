struct light_property
{
    vec3 ambience_color;
    vec3 diffuse_color;
    vec3 specular_color;
    vec4 position;
    vec4 direction;
    float catoff;
    //vec4 light_position;
    int type;//Directional = 0; Point =1; Spot =2.
};
uniform light_property u_light_property;

struct material_property
{
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};
uniform material_property u_material_property;

varying highp vec4 v_light_direction;
//varying highp mat4 v_view_matrix;
light_property v_light_property;

uniform sampler2D u_texture;
//uniform highp vec4 u_light_position;//////////////////////////////
uniform highp float u_light_power;
varying lowp vec4 color;
varying highp vec3 v_normal;
varying highp vec4 v_position;
varying highp vec2 texture;
uniform lowp bool texture_mode;
varying highp vec4 v_light_position;//
//varying highp vec4 eye_position;//------
//varying highp vec3 light_intensity;//

void main()
{
    if (!gl_FrontFacing) gl_FragColor = color;
    if (texture_mode==true){
//        v_light_property.ambience_color = u_light_property.ambience_color;
//        v_light_property.diffuse_color = u_light_property.diffuse_color;
//        v_light_property.specular_color = u_light_property.specular_color;
//        v_light_property.catoff = u_light_property.catoff;
//        v_light_property.type = u_light_property.type;
//        v_light_property.position = v_view_matrix*u_light_property.position;
//        v_light_property.direction = v_view_matrix*u_light_property.direction;

        vec3 light_vect;
        //Directional
//        if(u_light_property.type==0) light_vect = normalize(v_light_property.direction.xyz);
//        else{
//            light_vect = normalize(v_position.xyz - v_light_property.direction).xyz;
            //Spot
//            if(u_light_property.type==0){
//                float angle = acos(dot(v_light_property.direction, light_vect));
//                if(angle>v_light_property.catoff) light_vect = vec3(0.0, 0.0, 0.0);
//            }
//        }

        vec4 result_color = vec4(0.0, 0.0, 0.0, 0.0);
        vec4 eye_position = vec4(0.0, 0.0, 0.0, 1.0);
        vec4 light_color = vec4(1.0, 1.0, 1.0, 0.0);
        vec4 diff_mat_color = texture2D(u_texture, texture);
        vec3 eye_vect = normalize(v_position.xyz - eye_position.xyz);
        light_vect = normalize(v_position.xyz - v_light_position.xyz);
        //vec3 light_dir = normalize(u_light_property.light_position.xyz-v_position.xyz);
        vec3 reflect_light = normalize(reflect(light_vect, v_normal));
        //float dist = length(v_position.xyz - eye_position.xyz);
        float specular_factor = 5.0;
        float ambient_factor = 0.3;

        vec4 diff_color = vec4(u_material_property.diffuse, 1.0)*light_color*u_light_power*max(0.0, dot(v_normal, -light_vect));///(1.0+0.25*dist*dist);
        result_color+=diff_color;
        vec4 ambient_color = vec4(u_material_property.ambient, 1.0)*ambient_factor*diff_mat_color;
        result_color+=ambient_color;
        //vec4 specular_color = vec4(1.0, 1.0, 1.0, 1.0)*u_light_power*pow(max(0.0, dot(reflect_light, -eye_vect)), specular_factor)/(1.0+0.25*dist*dist);
        //result_color+=specular_color;

        gl_FragColor = result_color*diff_mat_color;

        //vec4 diff_mat_color = texture2D(u_texture, texture);//
        //gl_FragColor = vec4(light_intensity, 1.0)*diff_mat_color;//
    }
    else if (texture_mode==false) gl_FragColor = color;

}
