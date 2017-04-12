#include <lime_field_ids.h>
#include <math/Matrix3.h>


using namespace lime::field_ids;


namespace lime {
	
	
	Matrix3::Matrix3 () {
		
		a = 1;
		b = 0;
		c = 0;
		d = 1;
		tx = 0;
		ty = 0;
		
	}
	
	
	Matrix3::Matrix3 (double a, double b, double c, double d, double tx, double ty) {
		
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->tx = tx;
		this->ty = ty;
		
	}
	
	
	Matrix3::Matrix3 (value mat3) {
		
		a = val_number (val_field (mat3, id_a));
		b = val_number (val_field (mat3, id_b));
		c = val_number (val_field (mat3, id_c));
		d = val_number (val_field (mat3, id_d));
		tx = val_number (val_field (mat3, id_tx));
		ty = val_number (val_field (mat3, id_ty));
		
	}
	
	
	value Matrix3::Value () {
		
		value result = alloc_empty_object ();
		alloc_field (result, id_a, alloc_float (a));
		alloc_field (result, id_b, alloc_float (b));
		alloc_field (result, id_c, alloc_float (c));
		alloc_field (result, id_d, alloc_float (d));
		alloc_field (result, id_tx, alloc_float (tx));
		alloc_field (result, id_ty, alloc_float (ty));
		return result;
		
	}
	
	
}
