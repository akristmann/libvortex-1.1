/**
 * C server skel to implement services exported by the XML-RPC
 * component: test.
 *
 * This file was generated by xml-rpc-gen tool, from Vortex Library
 * project. 
 *
 * Vortex Library homepage:           http://vortex.aspl.es
 * Axl Library homepage:              http://xml.aspl.es
 * Advanced Software Production Line: http://www.aspl.es
 */
/* include base library */
#include <vortex.h>
/* include xml-rpc library */
#include <vortex_xml_rpc.h>
#include <test_types.h>

int get_the_bool_1_0 (char ** fault_error, int * fault_code, VortexChannel * channel)
{
	
		/* return false */
		return false;
	
}

/* This is a support function to invoke 'get_the_bool_1' service , do not modify it!! */
XmlRpcMethodResponse * __get_the_bool_1_0 (XmlRpcMethodCall * method_call, VortexChannel * channel)
{
	/* error support variables */
	char * fault_error = NULL;
	int    fault_code  = -1;
	int    result = axl_false;

	/* call to the user implementation */
	result = get_the_bool_1_0 ( &fault_error, &fault_code, channel);

	/* check error reply looking at the fault_error */
	if (fault_error != NULL) {
		/* we have a error reply */
		return CREATE_FAULT_REPLY (fault_code, fault_error);
	}

	/* return reply generated */
	return CREATE_OK_REPLY (XML_RPC_BOOLEAN_VALUE, INT_TO_PTR (result));
}
