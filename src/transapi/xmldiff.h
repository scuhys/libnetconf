#ifndef _XMLDIFF_H
#define _XMLDIFF_H

#include <libxml/tree.h>
#include "yinparser.h"

/**
 * @ingroup transapi
 * @brief Enum specifying states of node in document
 */
typedef enum {XMLDIFF_ERR = -1, XMLDIFF_NONE = 0, XMLDIFF_ADD, XMLDIFF_REM, XMLDIFF_MOD} XMLDIFF_OP;

/**
 * @ingroup transapi
 * @brief structure for single diff entry
 */
struct xmldiff_entry {
	char * path;
	xmlNodePtr node;
	XMLDIFF_OP op;
};

/**
 * @ingroup transapi
 * @brief structure holding all differencies found in compared files
 */
struct xmldiff {
	struct xmldiff_entry * diff_list;
	int diff_count;
	int diff_alloc;
	XMLDIFF_OP all_stat;
};

/**
 * @ingroup transapi
 * @brief Destroy and free whole xmldiff structure
 *
 * @param diff	pointer to xmldiff structure
 */
void xmldiff_free (struct xmldiff * diff);

/**
 * @ingroup transapi
 * @brief Module top level function
 *
 * @param old		old version of XML document
 * @param new		new version of XML document
 * @param model	data model in YANG format
 *
 * @return xmldiff structure holding all differences between XML documents or NULL
 */
struct xmldiff * xmldiff_diff (xmlDocPtr old, xmlDocPtr new, struct model_tree * model);

#endif