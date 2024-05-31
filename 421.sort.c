     list sort( n )
     int n;

     {
     list fi, la, temp;
     extern list r;
     if ( r == NULL ) return( NULL );
     else if ( n>1 )
          return( merge( sort( n/2 ), sort( (n+1)/2 )));
     else     {
          fi = r; la = r;
          /*** Build list as long as possible ***/
          for ( r=r->next; r!=NULL; )
               if ( r->k >= la->k ) {
                    la->next = r;
                    la = r;
                    r = r->next;
                    }
               else if ( r->k <= fi->k ) {
                    temp = r;
                    r = r->next;
                    temp->next = fi;
                    fi = temp;
                    }
               else break;
          la->next = NULL;
          return( fi );
          }
     };
