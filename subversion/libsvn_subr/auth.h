/*
 * auth.h :  shared stuff internal to the subr library.
 *
 * ====================================================================
 *    Licensed to the Apache Software Foundation (ASF) under one
 *    or more contributor license agreements.  See the NOTICE file
 *    distributed with this work for additional information
 *    regarding copyright ownership.  The ASF licenses this file
 *    to you under the Apache License, Version 2.0 (the
 *    "License"); you may not use this file except in compliance
 *    with the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing,
 *    software distributed under the License is distributed on an
 *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 *    KIND, either express or implied.  See the License for the
 *    specific language governing permissions and limitations
 *    under the License.
 * ====================================================================
 */

#ifndef SVN_SUBR_AUTH_H
#define SVN_SUBR_AUTH_H

#include "svn_auth.h"

/* Helper for svn_config_{read|write}_auth_data.  Return a path to a
   file within ~/.subversion/auth/ that holds CRED_KIND credentials
   within REALMSTRING.  If no path is available *PATH will be set to
   NULL. */
svn_error_t *
svn_auth__file_path(const char **path,
                    const char *cred_kind,
                    const char *realmstring,
                    const char *config_dir,
                    apr_pool_t *pool);

/* Implementation of svn_auth_cleanup_walk() for the "simple" provider */
svn_error_t *
svn_auth__simple_cleanup_walk(svn_auth_baton_t *baton,
                              svn_auth_cleanup_callback cleanup,
                              void *cleanup_baton,
                              apr_hash_t *creds_cache,
                              apr_pool_t *scratch_pool);


#endif
