#ifndef INSTANCE_H

#define INSTANCE_H

#include "object_types.h"
#include "structure/objects.h"
#include "attribute_name.h"

void include_text_on_object_attribute(char* variable_name, char* attribute, void* text);

void include_number_on_object_attribute(char* variable_name, char* attribute, double number);

void attribution_on_circle(Circle *circle, char *attribute, void *text, char *variable_name);

void attribution_on_elipse(Elipse *elipse, char *attribute, void *text, char *variable_name);

void attribution_on_rectange(Rectangle *rectangle, char *attribute, void *text, char *variable_name);

void attribution_on_line(Line* line, char *attribute, void *text, char *variable_name);

void attribution_on_arc(Arc *arc, char *attribute, void *text, char *variable_name);

void print_no_attribute(char *variable_name, char *attribue);

double parse_double(void* text);

Drawable* init_drawable();

Drawable* init_drawable() {
  return (Drawable*) malloc(sizeof(Drawable));
}

double parse_double(void* text) {
  return *((double*) text);
}
/**
 * This function identifies which object type is passed pushing
 * it for object stack with your value
 */
void instance_object(char *variable_name, char *type_name) {
  void * structure;
  StructureType object_type;

  if(strcmp(type_name, CIRCLE_NAME) == 0) {
    Circle* circle = (Circle*) malloc(sizeof(Circle));
    circle->drawable = init_drawable();
    structure = circle;
    object_type = CIRCLE;
  }

  if(strcmp(type_name, ELIPSE_NAME) == 0) {
    Elipse* elipse = (Elipse*) malloc(sizeof(Elipse));
    elipse->drawable = init_drawable();
    structure = elipse;
    object_type = ELIPSE;
  }

  if(strcmp(type_name, RECTANGLE_NAME) == 0) {
    Rectangle* rectangle = malloc(sizeof(Rectangle));
    rectangle->drawable = init_drawable();
    structure = rectangle;
    object_type = RECTANGLE;
  }

  if(strcmp(type_name, LINE_NAME) == 0) {
    Line* line = (Line*) malloc(sizeof(Line));
    line->drawable = init_drawable();
    structure = init_drawable();
    object_type = LINE;
  }

  if(strcmp(type_name, ARC_NAME) == 0) {
    Arc* arc = (Arc*) malloc(sizeof(Arc));
    arc->drawable = init_drawable();
    structure = arc;
    object_type = ARC;
  }

  int pushed = push(variable_name, current_scope_id, structure, object_type);

  if(pushed) {
    printf(">> #%s<%s>\n", variable_name, type_name);
  } else {
    printf(">> Variable '%s' already used\n", variable_name);
  }

}

void include_text_on_object_attribute(char* variable_name, char* attribute, void *text) {
  ObjectNode *node = search_element(variable_name);

  if(node == NULL) {
    printf(">>  ERROR: Attempt to access non-existing entitie %s", variable_name);
  } else {
    switch(node->object_type) {
      case CIRCLE:
        attribution_on_circle((Circle*) node->structure, attribute, text, variable_name);
      break;
      case ELIPSE:
        attribution_on_elipse((Elipse*) node->structure, attribute, text, variable_name);
      break;
      case RECTANGLE:
        attribution_on_rectange((Rectangle*) node->structure, attribute, text, variable_name);
      break;
      case LINE:
        attribution_on_line((Line*) node->structure, attribute, text, variable_name);
      break;
      case ARC:
        attribution_on_arc((Arc*) node->structure, attribute, text, variable_name);
      break;
      case VAR_TEXT:
        print_no_attribute(variable_name, attribute);
      break;
      case VAR_NUMBER:
        print_no_attribute(variable_name, attribute);
      break;
    }
  }
}

void include_number_on_object_attribute(char* variable_name, char* attribute, double number) {
  double *number_pointer = malloc(sizeof(double));
  *number_pointer = number;
  include_text_on_object_attribute(variable_name, attribute, number_pointer);
}

void attribution_on_circle(Circle *circle, char *attribute, void *text, char *variable_name) {
  if(strcmp(attribute, RADIUS) == 0) {
    circle->radius = *((double*) text);
  } else if(strcmp(attribute, BACKGROUND) == 0) {
    circle->drawable->background = (char*) text;
  } else if(strcmp(attribute, X) == 0) {
    circle->drawable->position_x = parse_double(text);
  } else if(strcmp(attribute, Y) == 0) {
    circle->drawable->position_y = parse_double(text);
  } else if(strcmp(attribute, LINE_WIDTH) == 0) {
    circle->drawable->line_width = parse_double(text);
  } else {
    print_no_attribute(variable_name, attribute);
  }
}

void attribution_on_elipse(Elipse *elipse, char *attribute, void *text, char *variable_name) {
  // TODO
}

void attribution_on_rectange(Rectangle *rectangle, char *attribute, void *text, char *variable_name) {
  if(strcmp(attribute, X)==0) {
    printf("alterando o x1");
  } else if(strcmp(attribute, X1)==0) {
    printf("alterando o x2");
  } else if(strcmp(attribute, X2)==0) {
    printf("alterando o x3");
  } else if(strcmp(attribute, X3)==0) {
    printf("alterando o x4");
  } else if(strcmp(attribute, Y)==0) {
    printf("alterando o y1");
  } else if(strcmp(attribute, Y1)==0) {
    printf("alterando o y2");
  } else if(strcmp(attribute, Y2)==0) {
    printf("alterando o y3");
  } else if(strcmp(attribute, Y3)==0) {
    printf("alterando o y4");
  } else if(strcmp(attribute, BACKGROUND)==0) {
    printf("alterando o background");
  } else if(strcmp(attribute, LINE_WIDTH) == 0){
    printf("alterando o lineWidth");
  } else {
    print_no_attribute(variable_name, attribute);
  }
}

void attribution_on_line(Line* line, char *attribute, void *text, char *variable_name) {
  if(strcmp(attribute, X1)==0) {
    line->drawable->position_x = parse_double(text);
  } else if(strcmp(attribute, X2)==0) {
    line->second_position_x = parse_double(text);
  } else if(strcmp(attribute, Y1)==0) {
    line->drawable->position_y = parse_double(text);
  } else if(strcmp(attribute, Y2)==0) {
    line->second_position_y = parse_double(text);
  } else if(strcmp(attribute, BACKGROUND)==0) {
    line->drawable->background = text;
  } else if(strcmp(attribute, LINE_WIDTH) == 0){
    line->drawable->line_width = parse_double(text);
  } else {
    print_no_attribute(variable_name, attribute);
  }
}

void attribution_on_arc(Arc *arc, char *attribute, void *text, char *variable_name) {
  if(strcmp(attribute, CENTER_X)==0) {
    arc->drawable->position_x = parse_double(text);
  } else if(strcmp(attribute, CENTER_Y)==0) {
    arc->drawable->position_y = parse_double(text);
  } else if(strcmp(attribute, START_ANGLE)==0) {
    arc->start_angle = parse_double(text);
  } else if(strcmp(attribute, FINAL_ANGLE)==0) {
    arc->final_angle = parse_double(text);
  } else {
    print_no_attribute(variable_name, attribute);
  }
}

void print_no_attribute(char *variable_name, char *attribute) {
  printf(">> Error variable %s has no attribute %s", variable_name, attribute);
}

#endif
