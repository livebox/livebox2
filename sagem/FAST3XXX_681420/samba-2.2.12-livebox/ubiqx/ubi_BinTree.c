/* ========================================================================== **
 *                              ubi_BinTree.c
 *
 *  Copyright (C) 1991-1998 by Christopher R. Hertel
 *
 *  Email:  crh@ubiqx.mn.org
 * -------------------------------------------------------------------------- **
 *
 *  This module implements a simple binary tree.
 *
 * -------------------------------------------------------------------------- **
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public
 *  License along with this library; if not, write to the Free
 *  Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * -------------------------------------------------------------------------- **
 *
 * Log: ubi_BinTree.c,v
 * Revision 4.10  2000/06/06 20:38:40  crh
 * In the ReplaceNode() function, the old node header was being copied
 * to the new node header using a byte-by-byte copy.  This was causing
 * the 'insure' software testing program to report a memory leak.  The
 * fix was to do a simple assignement: *newnode = *oldnode;
 * This quieted the (errant) memory leak reports and is probably a bit
 * faster than the bytewise copy.
 *
 * Revision 4.9  2000/01/08 23:24:30  crh
 * Clarified a variety of if( pointer ) lines, replacing them with
 * if( NULL != pointer ).  This is more correct, and I have heard
 * of at least one (obscure?) system out there that uses a non-zero
 * value for NULL.
 * Also, speed improvement in Neighbor().  It was comparing pointers
 * when it could have compared two gender values.  The pointer
 * comparison was somewhat indirect (does pointer equal the pointer
 * of the parent of the node pointed to by pointer).  Urq.
 *
 * Revision 4.8  1999/09/22 03:40:30  crh
 * Modified ubi_btTraverse() and ubi_btKillTree().  They now return an
 * unsigned long indicating the number of nodes processed.  The change
 * is subtle.  An empty tree formerly returned False, and now returns
 * zero.
 *
 * Revision 4.7  1998/10/21 06:14:42  crh
 * Fixed bugs in FirstOf() and LastOf() reported by Massimo Campostrini.
 * See function comments.
 *
 * Revision 4.6  1998/07/25 17:02:10  crh
 * Added the ubi_trNewTree() macro.
 *
 * Revision 4.5  1998/06/04 21:29:27  crh
 * Upper-cased defined constants (eg UBI_BINTREE_H) in some header files.
 * This is more "standard", and is what people expect.  Weird, eh?
 *
 * Revision 4.4  1998/06/03 17:42:46  crh
 * Further fiddling with sys_include.h.  It's now in ubi_BinTree.h which is
 * included by all of the binary tree files.
 *
 * Reminder: Some of the ubi_tr* macros in ubi_BinTree.h are redefined in
 *           ubi_AVLtree.h and ubi_SplayTree.h.  This allows easy swapping
 *           of tree types by simply changing a header.  Unfortunately, the
 *           macro redefinitions in ubi_AVLtree.h and ubi_SplayTree.h will
 *           conflict if used together.  You must either choose a single tree
 *           type, or use the underlying function calls directly.  Compare
 *           the two header files for more information.
 *
 * Revision 4.3  1998/06/02 01:28:43  crh
 * Changed ubi_null.h to sys_include.h to make it more generic.
 *
 * Revision 4.2  1998/05/20 04:32:36  crh
 * The C file now includes ubi_null.h.  See ubi_null.h for more info.
 * Also, the balance and gender fields of the node were declared as
 * signed char.  As I understand it, at least one SunOS or Solaris
 * compiler doesn't like "signed char".  The declarations were
 * wrong anyway, so I changed them to simple "char".
 *
 * Revision 4.1  1998/03/31 06:11:57  crh
 * Thomas Aglassinger sent E'mail pointing out errors in the
 * dereferencing of function pointers, and a missing typecast.
 * Thanks, Thomas!
 *
 * Revision 4.0  1998/03/10 03:19:22  crh
 * Added the AVL field 'balance' to the ubi_btNode structure.  This means
 * that all BinTree modules now use the same basic node structure, which
 * greatly simplifies the AVL module.
 * Decided that this was a big enough change to justify a new major revision
 * number.  3.0 was an error, so we're at 4.0.
 *
 * Revision 2.6  1998/01/24 06:27:46  crh
 * Added ubi_trCount() macro.
 *
 * Revision 2.5  1997/12/23 03:56:29  crh
 * In this version, all constants & macros defined in the header file have
 * the ubi_tr prefix.  Also cleaned up anything that gcc complained about
 * when run with '-pedantic -fsyntax-only -Wall'.
 *
 * Revision 2.4  1997/07/26 04:11:10  crh
 * + Just to be annoying I changed ubi_TRUE and ubi_FALSE to ubi_trTRUE
 *   and ubi_trFALSE.
 * + There is now a type ubi_trBool to go with ubi_trTRUE and ubi_trFALSE.
 * + There used to be something called "ubi_TypeDefs.h".  I got rid of it.
 * + Added function ubi_btLeafNode().
 *
 * Revision 2.3  1997/06/03 05:16:17  crh
 * Changed TRUE and FALSE to ubi_TRUE and ubi_FALSE to avoid conflicts.
 * Also changed the interface to function InitTree().  See the comments
 * for this function for more information.
 *
 * Revision 2.2  1995/10/03 22:00:07  CRH
 * Ubisized!
 *
 * Revision 2.1  95/03/09  23:37:10  CRH
 * Added the ModuleID static string and function.  These modules are now
 * self-identifying.
 *
 * Revision 2.0  95/02/27  22:00:17  CRH
 * Revision 2.0 of this program includes the following changes:
 *
 *     1)  A fix to a major typo in the RepaceNode() function.
 *     2)  The addition of the static function Border().
 *     3)  The addition of the public functions FirstOf() and LastOf(), which
 *         use Border(). These functions are used with trees that allow
 *         duplicate keys.
 *     4)  A complete rewrite of the Locate() function.  Locate() now accepts
 *         a "comparison" operator.
 *     5)  Overall enhancements to both code and comments.
 *
 * I decided to give this a new major rev number because the interface has
 * changed.  In particular, there are two new functions, and changes to the
 * Locate() function.
 *
 * Revision 1.0  93/10/15  22:44:59  CRH
 * With this revision, I have added a set of #define's that provide a single,
 * standard API to all existing tree modules.  Until now, each of the three
 * existing modules had a different function and typedef prefix, as follows:
 *
 *       Module        Prefix
 *     ubi_BinTree     ubi_bt
 *     ubi_AVLtree     ubi_avl
 *     ubi_SplayTree   ubi_spt
 *
 * To further complicate matters, only those portions of the base module
 * (ubi_BinTree) that were superceeded in the new module had the new names.
 * For example, if you were using ubi_SplayTree, the locate function was
 * called "ubi_sptLocate", but the next and previous functions remained
 * "ubi_btNext" and "ubi_btPrev".
 *
 * This was not too terrible if you were familiar with the modules and knew
 * exactly which tree model you wanted to use.  If you wanted to be able to
 * change modules (for speed comparisons, etc), things could get messy very
 * quickly.
 *
 * So, I have added a set of defined names that get redefined in any of the
 * descendant modules.  To use this standardized interface in your code,
 * simply replace all occurances of "ubi_bt", "ubi_avl", and "ubi_spt" with
 * "ubi_tr".  The "ubi_tr" names will resolve to the correct function or
 * datatype names for the module that you are using.  Just remember to
 * include the header for that module in your program file.  Because these
 * names are handled by the preprocessor, there is no added run-time
 * overhead.
 *
 * Note that the original names do still exist, and can be used if you wish
 * to write code directly to a specific module.  This should probably only be
 * done if you are planning to implement a new descendant type, such as
 * red/black trees.  CRH
 *
 *  V0.0 - June, 1991   -  Written by Christopher R. Hertel (CRH).
 *
 * ========================================================================== **
 */

#include "ubi_BinTree.h"  /* Header for this module.   */
#include "includes.h"
/* ========================================================================== **
 * Static data.
 */

static char ModuleID[] = "ubi_BinTree\n\
\tRevision: 4.10 \n\
\tDate: 2000/06/06 20:38:40 \n\
\tAuthor: crh \n";

/* ========================================================================== **
 * Internal (private) functions.
 */

static ubi_btNodePtr qFind( ubi_btCompFunc cmp,
			    ubi_btItemPtr  FindMe,
		   register ubi_btNodePtr  p )
  /* ------------------------------------------------------------------------ **
   * This function performs a non-recursive search of a tree for a node
   * matching a specific key.  It is called "qFind()" because it is
   * faster that TreeFind (below).
   *
   *  Input:
   *     cmp      -  a pointer to the tree's comparison function.
   *     FindMe   -  a pointer to the key value for which to search.
   *     p        -  a pointer to the starting point of the search.  <p>
   *                 is considered to be the root of a subtree, and only
   *                 the subtree will be searched.
   *
   *  Output:
   *     A pointer to a node with a key that matches the key indicated by
   *     FindMe, or NULL if no such node was found.
   *
   *  Note:   In a tree that allows duplicates, the pointer returned *might
   *          not* point to the (sequentially) first occurance of the
   *          desired key.
   * ------------------------------------------------------------------------ **
   */
  {
  int tmp;

  while( (NULL != p)
      && ((tmp = ubi_trAbNormal( (*cmp)(FindMe, p) )) != ubi_trEQUAL) )
    p = p->Link[tmp];

  return( p );
  } /* qFind */

static ubi_btNodePtr TreeFind( ubi_btItemPtr  findme,
			       ubi_btNodePtr  p,
			       ubi_btNodePtr *parentp,
			       char          *gender,
			       ubi_btCompFunc CmpFunc )
  /* ------------------------------------------------------------------------ **
   * TreeFind() searches a tree for a given value (findme).  It will return a
   * pointer to the target node, if found, or NULL if the target node was not
   * found.
   *
   * TreeFind() also returns, via parameters, a pointer to the parent of the
   * target node, and a LEFT or RIGHT value indicating which child of the
   * parent is the target node.  *If the target is not found*, then these
   * values indicate the place at which the target *should be found*.  This
   * is useful when inserting a new node into a tree or searching for nodes
   * "near" the target node.
   *
   * The parameters are:
   *
   *  findme   -  is a pointer to the key information to be searched for.
   *  p        -  points to the root of the tree to be searched.
   *  parentp  -  will return a pointer to a pointer to the !parent! of the
   *              target node, which can be especially usefull if the target
   *              was not found.
   *  gender   -  returns LEFT or RIGHT to indicate which child of *parentp
   *              was last searched.
   *  CmpFunc  -  points to the comparison function.
   *
   * This function is called by ubi_btLocate() and ubi_btInsert().
   * ------------------------------------------------------------------------ **
   */
  {
  register ubi_btNodePtr tmp_p      = p;
  ubi_btNodePtr          tmp_pp     = NULL;
  char                   tmp_gender = ubi_trEQUAL;
  int                    tmp_cmp;

  while( (NULL != tmp_p)
     && (ubi_trEQUAL != (tmp_cmp = ubi_trAbNormal((*CmpFunc)(findme, tmp_p)))) )
    {
    tmp_pp     = tmp_p;                 /* Keep track of previous node. */
    tmp_gender = (char)tmp_cmp;         /* Keep track of sex of child.  */
    tmp_p      = tmp_p->Link[tmp_cmp];  /* Go to child. */
    }
  *parentp = tmp_pp;                /* Return results. */
  *gender  = tmp_gender;
  return( tmp_p );
  } /* TreeFind */

static void ReplaceNode( ubi_btNodePtr *parent,
			 ubi_btNodePtr  oldnode,
			 ubi_btNodePtr  newnode )
  /* ------------------------------------------------------------------------ **
   * Remove node oldnode from the tree, replacing it with node newnode.
   *
   * Input:
   *  parent   - A pointer to he parent pointer of the node to be
   *             replaced.  <parent> may point to the Link[] field of
   *             a parent node, or it may indicate the root pointer at
   *             the top of the tree.
   *  oldnode  - A pointer to the node that is to be replaced.
   *  newnode  - A pointer to the node that is to be installed in the
   *             place of <*oldnode>.
   *
   * Notes:    Don't forget to free oldnode.
   *           Also, this function used to have a really nasty typo
   *           bug.  "oldnode" and "newnode" were swapped in the line
   *           that now reads:
   *     ((unsigned char *)newnode)[i] = ((unsigned char *)oldnode)[i];
   *           Bleah!
   * ------------------------------------------------------------------------ **
   */
  {
  *newnode = *oldnode;  /* Copy node internals to new node. */

  (*parent) = newnode;  /* Old node's parent points to new child. */
  /* Now tell the children about their new step-parent. */
  if( oldnode->Link[ubi_trLEFT] )
    (oldnode->Link[ubi_trLEFT])->Link[ubi_trPARENT] = newnode;
  if( oldnode->Link[ubi_trRIGHT] )
    (oldnode->Link[ubi_trRIGHT])->Link[ubi_trPARENT] = newnode;
  } /* ReplaceNode */

static void SwapNodes( ubi_btRootPtr RootPtr,
		       ubi_btNodePtr Node1,
		       ubi_btNodePtr Node2 )

  {
	DEBUG(1,("function ommited\n"));
	/* function ommited*/
  } /* SwapNodes */

/* -------------------------------------------------------------------------- **
 * These routines allow you to walk through the tree, forwards or backwards.
 */

static ubi_btNodePtr SubSlide( register ubi_btNodePtr P,
			       register int           whichway )
  /* ------------------------------------------------------------------------ **
   * Slide down the side of a subtree.
   *
   * Given a starting node, this function returns a pointer to the LEFT-, or
   * RIGHT-most descendent, *or* (if whichway is PARENT) to the tree root.
   *
   *  Input:  P         - a pointer to a starting place.
   *          whichway  - the direction (LEFT, RIGHT, or PARENT) in which to
   *                      travel.
   *  Output: A pointer to a node that is either the root, or has no
   *          whichway-th child but is within the subtree of P.  Note that
   *          the return value may be the same as P.  The return value *will
   *          be* NULL if P is NULL.
   * ------------------------------------------------------------------------ **
   */
  {

  if( NULL != P )
    while( NULL != P->Link[ whichway ] )
      P = P->Link[ whichway ];
  return( P );
  } /* SubSlide */

static ubi_btNodePtr Neighbor( register ubi_btNodePtr P,
			       register int           whichway )
  /* ------------------------------------------------------------------------ **
   * Given starting point p, return the (key order) next or preceeding node
   * in the tree.
   *
   *  Input:  P         - Pointer to our starting place node.
   *          whichway  - the direction in which to travel to find the
   *                      neighbor, i.e., the RIGHT neighbor or the LEFT
   *                      neighbor.
   *
   *  Output: A pointer to the neighboring node, or NULL if P was NULL.
   *
   *  Notes:  If whichway is PARENT, the results are unpredictable.
   * ------------------------------------------------------------------------ **
   */
  {
  if( P )
    {
    if( NULL != P->Link[ whichway ] )
      return( SubSlide( P->Link[ whichway ], (char)ubi_trRevWay(whichway) ) );
    else
      while( NULL != P->Link[ ubi_trPARENT ] )
	{
	if( whichway == P->gender )
	  P = P->Link[ ubi_trPARENT ];
	else
	  return( P->Link[ ubi_trPARENT ] );
	}
    }
  return( NULL );
  } /* Neighbor */

static ubi_btNodePtr Border( ubi_btRootPtr RootPtr,
			     ubi_btItemPtr FindMe,
			     ubi_btNodePtr p,
			     int           whichway )
  {
	DEBUG(1,("function ommited\n"));
	/* function ommited*/
  } /* Border */


/* ========================================================================== **
 * Exported utilities.
 */

long ubi_btSgn( register long x )
  /* ------------------------------------------------------------------------ **
   * Return the sign of x; {negative,zero,positive} ==> {-1, 0, 1}.
   *
   *  Input:  x - a signed long integer value.
   *
   *  Output: the "sign" of x, represented as follows:
   *            -1 == negative
   *             0 == zero (no sign)
   *             1 == positive
   *
   * Note: This utility is provided in order to facilitate the conversion
   *       of C comparison function return values into BinTree direction
   *       values: {LEFT, PARENT, EQUAL}.  It is INCORPORATED into the
   *       ubi_trAbNormal() conversion macro!
   *
   * ------------------------------------------------------------------------ **
   */
  {
  return( (x)?((x>0)?(1):(-1)):(0) );
  } /* ubi_btSgn */

ubi_btNodePtr ubi_btInitNode( ubi_btNodePtr NodePtr )
  /* ------------------------------------------------------------------------ **
   * Initialize a tree node.
   *
   *  Input:  a pointer to a ubi_btNode structure to be initialized.
   *  Output: a pointer to the initialized ubi_btNode structure (ie. the
   *          same as the input pointer).
   * ------------------------------------------------------------------------ **
   */
  {
  NodePtr->Link[ ubi_trLEFT ]   = NULL;
  NodePtr->Link[ ubi_trPARENT ] = NULL;
  NodePtr->Link[ ubi_trRIGHT ]  = NULL;
  NodePtr->gender               = ubi_trEQUAL;
  NodePtr->balance              = ubi_trEQUAL;
  return( NodePtr );
  } /* ubi_btInitNode */

ubi_btRootPtr ubi_btInitTree( ubi_btRootPtr   RootPtr,
			      ubi_btCompFunc  CompFunc,
			      char            Flags )
  /* ------------------------------------------------------------------------ **
   * Initialize the fields of a Tree Root header structure.
   *
   *  Input:   RootPtr   - a pointer to an ubi_btRoot structure to be
   *                       initialized.
   *           CompFunc  - a pointer to a comparison function that will be used
   *                       whenever nodes in the tree must be compared against
   *                       outside values.
   *           Flags     - One bytes worth of flags.  Flags include
   *                       ubi_trOVERWRITE and ubi_trDUPKEY.  See the header
   *                       file for more info.
   *
   *  Output:  a pointer to the initialized ubi_btRoot structure (ie. the
   *           same value as RootPtr).
   *
   *  Note:    The interface to this function has changed from that of
   *           previous versions.  The <Flags> parameter replaces two
   *           boolean parameters that had the same basic effect.
   *
   * ------------------------------------------------------------------------ **
   */
  {
  if( RootPtr )
    {
    RootPtr->root   = NULL;
    RootPtr->count  = 0L;
    RootPtr->cmp    = CompFunc;
    RootPtr->flags  = (Flags & ubi_trDUPKEY) ? ubi_trDUPKEY : Flags;
    }                 /* There are only two supported flags, and they are
		       * mutually exclusive.  ubi_trDUPKEY takes precedence
		       * over ubi_trOVERWRITE.
		       */
  return( RootPtr );
  } /* ubi_btInitTree */

ubi_trBool ubi_btInsert( ubi_btRootPtr  RootPtr,
			 ubi_btNodePtr  NewNode,
			 ubi_btItemPtr  ItemPtr,
			 ubi_btNodePtr *OldNode )
  /* ------------------------------------------------------------------------ **
   * This function uses a non-recursive algorithm to add a new element to the
   * tree.
   *
   *  Input:   RootPtr  -  a pointer to the ubi_btRoot structure that indicates
   *                       the root of the tree to which NewNode is to be added.
   *           NewNode  -  a pointer to an ubi_btNode structure that is NOT
   *                       part of any tree.
   *           ItemPtr  -  A pointer to the sort key that is stored within
   *                       *NewNode.  ItemPtr MUST point to information stored
   *                       in *NewNode or an EXACT DUPLICATE.  The key data
   *                       indicated by ItemPtr is used to place the new node
   *                       into the tree.
   *           OldNode  -  a pointer to an ubi_btNodePtr.  When searching
   *                       the tree, a duplicate node may be found.  If
   *                       duplicates are allowed, then the new node will
   *                       be simply placed into the tree.  If duplicates
   *                       are not allowed, however, then one of two things
   *                       may happen.
   *                       1) if overwritting *is not* allowed, this
   *                          function will return FALSE (indicating that
   *                          the new node could not be inserted), and
   *                          *OldNode will point to the duplicate that is
   *                          still in the tree.
   *                       2) if overwritting *is* allowed, then this
   *                          function will swap **OldNode for *NewNode.
   *                          In this case, *OldNode will point to the node
   *                          that was removed (thus allowing you to free
   *                          the node).
   *                          **  If you are using overwrite mode, ALWAYS  **
   *                          ** check the return value of this parameter! **
   *                 Note: You may pass NULL in this parameter, the
   *                       function knows how to cope.  If you do this,
   *                       however, there will be no way to return a
   *                       pointer to an old (ie. replaced) node (which is
   *                       a problem if you are using overwrite mode).
   *
   *  Output:  a boolean value indicating success or failure.  The function
   *           will return FALSE if the node could not be added to the tree.
   *           Such failure will only occur if duplicates are not allowed,
   *           nodes cannot be overwritten, AND a duplicate key was found
   *           within the tree.
   * ------------------------------------------------------------------------ **
   */
  {
  ubi_btNodePtr OtherP,
		parent = NULL;
  char          tmp;

  if( NULL == OldNode ) /* If they didn't give us a pointer, supply our own.  */
    OldNode = &OtherP;

  (void)ubi_btInitNode( NewNode );     /* Init the new node's BinTree fields. */

  /* Find a place for the new node. */
  *OldNode = TreeFind(ItemPtr, (RootPtr->root), &parent, &tmp, (RootPtr->cmp));

  /* Now add the node to the tree... */
  if( NULL == (*OldNode) )  /* The easy one: we have a space for a new node!  */
    {
    if( NULL == parent )
      RootPtr->root = NewNode;
    else
      {
      parent->Link[(int)tmp]      = NewNode;
      NewNode->Link[ubi_trPARENT] = parent;
      NewNode->gender             = tmp;
      }
    (RootPtr->count)++;
    return( ubi_trTRUE );
    }

  /* If we reach this point, we know that a duplicate node exists.  This
   * section adds the node to the tree if duplicate keys are allowed.
   */
  if( ubi_trDups_OK(RootPtr) )    /* Key exists, add duplicate */
    {
    ubi_btNodePtr q;

    tmp = ubi_trRIGHT;
    q = (*OldNode);
    *OldNode = NULL;
    while( NULL != q )
      {
      parent = q;
      if( tmp == ubi_trEQUAL )
	tmp = ubi_trRIGHT;
      q = q->Link[(int)tmp];
      if ( q )
	tmp = ubi_trAbNormal( (*(RootPtr->cmp))(ItemPtr, q) );
      }
    parent->Link[(int)tmp]       = NewNode;
    NewNode->Link[ubi_trPARENT]  = parent;
    NewNode->gender              = tmp;
    (RootPtr->count)++;
    return( ubi_trTRUE );
    }

  /* If we get to *this* point, we know that we are not allowed to have
   * duplicate nodes, but our node keys match, so... may we replace the
   * old one?
   */
  if( ubi_trOvwt_OK(RootPtr) )    /* Key exists, we replace */
    {
    if( NULL == parent )
      ReplaceNode( &(RootPtr->root), *OldNode, NewNode );
    else
      ReplaceNode( &(parent->Link[(int)((*OldNode)->gender)]),
		   *OldNode, NewNode );
    return( ubi_trTRUE );
    }

  return( ubi_trFALSE );      /* Failure: could not replace an existing node. */
  } /* ubi_btInsert */

ubi_btNodePtr ubi_btRemove( ubi_btRootPtr RootPtr,
			    ubi_btNodePtr DeadNode )

  {
	DEBUG(1,("function ommited\n"));
	/* function ommited*/
  } /* ubi_btRemove */

ubi_btNodePtr ubi_btLocate( ubi_btRootPtr RootPtr,
			    ubi_btItemPtr FindMe,
			    ubi_trCompOps CompOp )

  {
	DEBUG(1,("function ommited\n"));
	/* function omited*/
  } /* ubi_btLocate */

ubi_btNodePtr ubi_btFind( ubi_btRootPtr RootPtr,
			  ubi_btItemPtr FindMe )
  /* ------------------------------------------------------------------------ **
   * This function performs a non-recursive search of a tree for any node
   * matching a specific key.
   *
   *  Input:
   *     RootPtr  -  a pointer to the header of the tree to be searched.
   *     FindMe   -  a pointer to the key value for which to search.
   *
   *  Output:
   *     A pointer to a node with a key that matches the key indicated by
   *     FindMe, or NULL if no such node was found.
   *
   *  Note:   In a tree that allows duplicates, the pointer returned *might
   *          not* point to the (sequentially) first occurance of the
   *          desired key.  In such a tree, it may be more useful to use
   *          ubi_btLocate().
   * ------------------------------------------------------------------------ **
   */
  {
  return( qFind( RootPtr->cmp, FindMe, RootPtr->root ) );
  } /* ubi_btFind */

ubi_btNodePtr ubi_btNext( ubi_btNodePtr P )
  /* ------------------------------------------------------------------------ **
   * Given the node indicated by P, find the (sorted order) Next node in the
   * tree.
   *  Input:   P  -  a pointer to a node that exists in a binary tree.
   *  Output:  A pointer to the "next" node in the tree, or NULL if P pointed
   *           to the "last" node in the tree or was NULL.
   * ------------------------------------------------------------------------ **
   */
  {
  return( Neighbor( P, ubi_trRIGHT ) );
  } /* ubi_btNext */

ubi_btNodePtr ubi_btPrev( ubi_btNodePtr P )

  {
	DEBUG(1,("function ommited\n"));
	/* function omited*/
  } /* ubi_btPrev */

ubi_btNodePtr ubi_btFirst( ubi_btNodePtr P )
  /* ------------------------------------------------------------------------ **
   * Given the node indicated by P, find the (sorted order) First node in the
   * subtree of which *P is the root.
   *  Input:   P  -  a pointer to a node that exists in a binary tree.
   *  Output:  A pointer to the "first" node in a subtree that has *P as its
   *           root.  This function will return NULL only if P is NULL.
   *  Note:    In general, you will be passing in the value of the root field
   *           of an ubi_btRoot structure.
   * ------------------------------------------------------------------------ **
   */
  {
  return( SubSlide( P, ubi_trLEFT ) );
  } /* ubi_btFirst */

ubi_btNodePtr ubi_btLast( ubi_btNodePtr P )

  {
	DEBUG(1,("function ommited\n"));
	/* function omited*/
  } /* ubi_btLast */

ubi_btNodePtr ubi_btFirstOf( ubi_btRootPtr RootPtr,
			     ubi_btItemPtr MatchMe,
			     ubi_btNodePtr p )

  {
	DEBUG(1,("function ommited\n"));
	/* function omited*/
  } /* ubi_btFirstOf */

ubi_btNodePtr ubi_btLastOf( ubi_btRootPtr RootPtr,
			    ubi_btItemPtr MatchMe,
			    ubi_btNodePtr p )

  {
	DEBUG(1,("function ommited\n"));
	/* function omited*/
  } /* ubi_btLastOf */

unsigned long ubi_btTraverse( ubi_btRootPtr   RootPtr,
			      ubi_btActionRtn EachNode,
			      void           *UserData )

  {
	DEBUG(1,("function ommited\n"));
	/* function omited*/
  } /* ubi_btTraverse */

unsigned long ubi_btKillTree( ubi_btRootPtr     RootPtr,
			      ubi_btKillNodeRtn FreeNode )
  /* ------------------------------------------------------------------------ **
   * Delete an entire tree (non-recursively) and reinitialize the ubi_btRoot
   * structure.  Return a count of the number of nodes deleted.
   *
   *  Input:   RootPtr  -  a pointer to an ubi_btRoot structure that indicates
   *                       the root of the tree to delete.
   *           FreeNode -  a function that will be called for each node in the
   *                       tree to deallocate the memory used by the node.
   *
   *  Output:  The number of nodes removed from the tree.
   *           A value of 0 will be returned if:
   *           - The tree actually contains 0 entries.
   *           - the value of <RootPtr> is NULL, in which case the tree is
   *             assumed to be empty
   *           - the value of <FreeNode> is NULL, in which case entries
   *             cannot be removed, so 0 is returned.  *Make sure that you
   *             provide a valid value for <FreeNode>*.
   *           In all other cases, you should get a positive value equal to
   *           the value of RootPtr->count upon entry.
   *
   * ------------------------------------------------------------------------ **
   */
  {
  ubi_btNodePtr p, q;
  unsigned long count = 0;

  if( (NULL == RootPtr) || (NULL == FreeNode) )
    return( 0 );

  p = ubi_btFirst( RootPtr->root );
  while( NULL != p )
    {
    q = p;
    while( q->Link[ubi_trRIGHT] )
      q = SubSlide( q->Link[ubi_trRIGHT], ubi_trLEFT );
    p = q->Link[ubi_trPARENT];
    if( NULL != p )
      p->Link[ ((p->Link[ubi_trLEFT] == q)?ubi_trLEFT:ubi_trRIGHT) ] = NULL;
    (*FreeNode)((void *)q);
    count++;
    }

  /* overkill... */
  (void)ubi_btInitTree( RootPtr,
			RootPtr->cmp,
			RootPtr->flags );
  return( count );
  } /* ubi_btKillTree */

ubi_btNodePtr ubi_btLeafNode( ubi_btNodePtr leader )

  {
	DEBUG(1,("function ommited\n"));
	/* function omited*/
  } /* ubi_btLeafNode */

int ubi_btModuleID( int size, char *list[] )

  {
	DEBUG(1,("function ommited\n"));
	/* function omited*/
  } /* ubi_btModuleID */


/* ========================================================================== */
