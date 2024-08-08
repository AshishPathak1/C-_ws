#pragma once

/*Describes a Point in X-Y plain */
class Point
{
private:
	//Data Members : Fields
	int x_cord;
	int y_cord;

	//Member function : Accessor Methods (Getter)
public:	
	/* Returns the x_coordinate of the Point in X-Y plain*/
	int get_x_cord() const {
		//x_cord++;
		return x_cord;
	}
	
	/* Returns the y_coordinate of the Point in X-Y plain*/
	int get_y_cord() const {
		//--y_cord;
		return y_cord;
	}

	//Member function : Modifiers Methods (Setter)
	
	/* Sets the x_coordinate of the Point in X-Y plain*/
	void set_x_cord(int x) {
		x_cord = x;
	}

	/* Sets the y_coordinate of the Point in X-Y plain*/
	void set_y_cord(int y) {
		y_cord = y;
	}
};

