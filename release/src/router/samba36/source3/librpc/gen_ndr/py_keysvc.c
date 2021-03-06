
/* Python wrapper functions auto-generated by pidl */
#include <Python.h>
#include "includes.h"
#include <pytalloc.h>
#include "librpc/rpc/pyrpc.h"
#include "librpc/rpc/pyrpc_util.h"
#include "librpc/gen_ndr/ndr_keysvc.h"
#include "librpc/gen_ndr/ndr_keysvc_c.h"

staticforward PyTypeObject keysvc_InterfaceType;

void initkeysvc(void);static PyTypeObject *ClientConnection_Type;

static bool pack_py_keysvc_Unknown0_args_in(PyObject *args, PyObject *kwargs, struct keysvc_Unknown0 *r)
{
	const char *kwnames[] = {
		NULL
	};

	if (!PyArg_ParseTupleAndKeywords(args, kwargs, ":keysvc_Unknown0", discard_const_p(char *, kwnames))) {
		return false;
	}

	return true;
}

static PyObject *unpack_py_keysvc_Unknown0_args_out(struct keysvc_Unknown0 *r)
{
	PyObject *result;
	result = Py_None;
	Py_INCREF(result);
	if (!W_ERROR_IS_OK(r->out.result)) {
		PyErr_SetWERROR(r->out.result);
		return NULL;
	}

	return result;
}

const struct PyNdrRpcMethodDef py_ndr_keysvc_methods[] = {
	{ "Unknown0", "S.Unknown0() -> None", (py_dcerpc_call_fn)dcerpc_keysvc_Unknown0_r, (py_data_pack_fn)pack_py_keysvc_Unknown0_args_in, (py_data_unpack_fn)unpack_py_keysvc_Unknown0_args_out, 0, &ndr_table_keysvc },
	{ NULL }
};

static PyObject *interface_keysvc_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	return py_dcerpc_interface_init_helper(type, args, kwargs, &ndr_table_keysvc);
}

#define PY_DOC_KEYSVC "Cryptographic Key Services"
static PyTypeObject keysvc_InterfaceType = {
	PyObject_HEAD_INIT(NULL) 0,
	.tp_name = "keysvc.keysvc",
	.tp_basicsize = sizeof(dcerpc_InterfaceObject),
	.tp_doc = "keysvc(binding, lp_ctx=None, credentials=None) -> connection\n"
"\n"
"binding should be a DCE/RPC binding string (for example: ncacn_ip_tcp:127.0.0.1)\n"
"lp_ctx should be a path to a smb.conf file or a param.LoadParm object\n"
"credentials should be a credentials.Credentials object.\n\n"PY_DOC_KEYSVC,
	.tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
	.tp_new = interface_keysvc_new,
};

static PyMethodDef keysvc_methods[] = {
	{ NULL, NULL, 0, NULL }
};

void initkeysvc(void)
{
	PyObject *m;
	PyObject *dep_samba_dcerpc_base;

	dep_samba_dcerpc_base = PyImport_ImportModule("samba.dcerpc.base");
	if (dep_samba_dcerpc_base == NULL)
		return;

	ClientConnection_Type = (PyTypeObject *)PyObject_GetAttrString(dep_samba_dcerpc_base, "ClientConnection");
	if (ClientConnection_Type == NULL)
		return;

	keysvc_InterfaceType.tp_base = ClientConnection_Type;

	if (PyType_Ready(&keysvc_InterfaceType) < 0)
		return;
	if (!PyInterface_AddNdrRpcMethods(&keysvc_InterfaceType, py_ndr_keysvc_methods))
		return;

#ifdef PY_KEYSVC_PATCH
	PY_KEYSVC_PATCH(&keysvc_InterfaceType);
#endif

	m = Py_InitModule3("keysvc", keysvc_methods, "keysvc DCE/RPC");
	if (m == NULL)
		return;

	Py_INCREF((PyObject *)(void *)&keysvc_InterfaceType);
	PyModule_AddObject(m, "keysvc", (PyObject *)(void *)&keysvc_InterfaceType);
#ifdef PY_MOD_KEYSVC_PATCH
	PY_MOD_KEYSVC_PATCH(m);
#endif

}
