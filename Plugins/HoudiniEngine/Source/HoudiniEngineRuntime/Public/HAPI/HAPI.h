/*
 * PROPRIETARY INFORMATION.  This software is proprietary to
 * Side Effects Software Inc., and is not to be reproduced,
 * transmitted, or disclosed in any way without written permission.
 *
 * Produced by:
 *      Side Effects Software Inc
 *      123 Front Street West, Suite 1401
 *      Toronto, Ontario
 *      Canada   M5J 2M2
 *      416-504-9876
 *
 * COMMENTS:
 * For parsing help, there is a variable naming convention we maintain:
 *      strings:            char * and does not end in "buffer"
 *      binary:             char * and is either exactly "buffer" or ends
 *                          with "_buffer"
 *      single values:      don't end with "_array" or "_buffer"
 *      arrays:             <type> * and is either "array" or ends
 *                          with "_array"
 *      array length:       is either "length", "count", or ends with
 *                          "_length" or "_count"
 */

#ifndef __HAPI_h__
#define __HAPI_h__

#include "HAPI_API.h"
#include "HAPI_Common.h"
#include "HAPI_Helpers.h"

// SESSION ------------------------------------------------------------------

/// @brief  Creates a new in-process session.  There can only be
///         one such session per host process.
///
/// @param[out]     session
///                 A ::HAPI_Session struct to receive the session id,
///                 in this case always 0.
///
HAPI_DECL HAPI_CreateInProcessSession( HAPI_Session * session );

/// @brief  Starts a Thrift RPC server process on the local host serving
///         clients on a TCP socket and waits for it to start serving.
///         It is safe to create an RPC session on local host using the
///         specified port after this call succeeds.
///
/// @param[in]      options
///                 Options to configure the server being started.
///
/// @param[in]      port
///                 The TCP socket to create on the server.
///
/// @param[out]     process_id
///                 The process id of the server, if started successfully.
///
HAPI_DECL HAPI_StartThriftSocketServer(
                                    const HAPI_ThriftServerOptions * options,
                                    int port,
                                    HAPI_ProcessId * process_id );

/// @brief  Creates a Thrift RPC session using a TCP socket as transport.
///
/// @param[out]     session
///                 A ::HAPI_Session struct to receive the unique session id
///                 of the new session.
///
/// @param[in]      host_name
///                 The name of the server host.
///
/// @param[in]      port
///                 The server port to connect to.
///
HAPI_DECL HAPI_CreateThriftSocketSession( HAPI_Session * session,
                                          const char * host_name,
                                          int port );

/// @brief  Starts a Thrift RPC server process on the local host serving
///         clients on a Windows named pipe or a Unix domain socket and
///         waits for it to start serving. It is safe to create an RPC
///         session using the specified pipe or socket after this call
///         succeeds.
///
/// @param[in]      options
///                 Options to configure the server being started.
///
/// @param[in]      pipe_name
///                 The name of the pipe or socket.
///
/// @param[out]     process_id
///                 The process id of the server, if started successfully.
///
HAPI_DECL HAPI_StartThriftNamedPipeServer(
                                    const HAPI_ThriftServerOptions * options,
                                    const char * pipe_name,
                                    HAPI_ProcessId * process_id );

/// @brief  Creates a Thrift RPC session using a Windows named pipe
///         or a Unix domain socket as transport.
///
/// @param[out]     session
///                 A ::HAPI_Session struct to receive the unique session id
///                 of the new session.
///
/// @param[in]      pipe_name
///                 The name of the pipe or socket.
///
HAPI_DECL HAPI_CreateThriftNamedPipeSession( HAPI_Session * session,
                                             const char * pipe_name );

/// @brief  Binds a new implementation DLL to one of the custom session
///         slots.
///
/// @param[in]      session_type
///                 Which custom implementation slot to bind the
///                 DLL to. Must be one of ::HAPI_SESSION_CUSTOM1,
///                 ::HAPI_SESSION_CUSTOM2, or ::HAPI_SESSION_CUSTOM3.
///
/// @param[in]      dll_path
///                 The path to the custom implementation DLL.
///
HAPI_DECL HAPI_BindCustomImplementation( HAPI_SessionType session_type,
                                         const char * dll_path );

/// @brief  Creates a new session using a custom implementation.
///         Note that the implementation DLL must already have
///         been bound to the session via calling
///         ::HAPI_BindCustomImplementation().
///
/// @param[in]      session_type
///                 session_type indicates which custom session
///                 slot to create the session on.
///
/// @param[in,out]  session_info
///                 Any data required by the custom implementation to
///                 create its session.
///
/// @param[out]     session
///                 A ::HAPI_Session struct to receive the session id,
///                 The sessionType parameter of the struct should
///                 also match the session_type parameter passed in.
///
HAPI_DECL HAPI_CreateCustomSession( HAPI_SessionType session_type,
                                    void * session_info,
                                    HAPI_Session * session );

/// @brief  Checks whether the session identified by ::HAPI_Session::id is
///         a valid session opened in the implementation identified by
///         ::HAPI_Session::type.
///
/// @param[in]      session
///                 The ::HAPI_Session to check.
///
/// @return         ::HAPI_RESULT_SUCCESS if the session is valid.
///                 Otherwise, the session is invalid and passing it to
///                 other HAPI calls may result in undefined behavior.
///
HAPI_DECL HAPI_IsSessionValid( const HAPI_Session * session );

/// @brief  Closes a session. If the session has been established using
///         RPC, then the RPC connection is closed.
///
/// @param[in]     session
///                The HAPI_Session to close. After this call, this
///                session is invalid and passing it to HAPI calls other
///                than ::HAPI_IsSessionValid() may result in undefined
///                behavior.
///
HAPI_DECL HAPI_CloseSession( const HAPI_Session * session );

// INITIALIZATION / CLEANUP -------------------------------------------------

/// @brief  Check whether the runtime has been initialized yet using
///         ::HAPI_Initialize(). Function will return ::HAPI_RESULT_SUCCESS
///         if the runtime has been initialized and ::HAPI_RESULT_NOT_INITIALIZED
///         otherwise.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
HAPI_DECL HAPI_IsInitialized( const HAPI_Session * session );

/// @brief  Create the asset manager, set up environment variables, and
///         initialize the main Houdini scene. No license checking is
///         during this step. Only when you try to load an asset library
///         (OTL) do we actually check for licenses.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      cook_options
///                 Global cook options used by subsequent default cooks.
///                 This can be overwritten by individual cooks but if
///                 you choose to instantiate assets with cook_on_load
///                 set to true then these cook options will be used.
///
/// @param[in]      use_cooking_thread
///                 Use a separate thread for cooking of assets. This
///                 allows for asynchronous cooking and larger stack size.
///
/// @param[in]      cooking_thread_stack_size
///                 Set the stack size of the cooking thread. Use -1 to
///                 set the stack size to the Houdini default. This
///                 value is in bytes.
///
/// @param[in]      houdini_environment_files
///                 A list of paths, separated by a ";" on Windows and a ":"
///                 on Linux and Mac, to .env files that follow the same
///                 syntax as the houdini.env file in Houdini's user prefs
///                 folder. These will be applied after the default
///                 houdini.env file and will overwrite the process'
///                 environment variable values. You an use this to enforce
///                 a stricter environment when running engine.
///                 For more info, see:
///                 http://www.sidefx.com/docs/houdini/basics/config_env
///
/// @param[in]      otl_search_path
///                 The directory where OTLs are searched for. You can
///                 pass NULL here which will only use the default
///                 Houdini OTL search paths. You can also pass in
///                 multiple paths separated by a ";" on Windows and a ":"
///                 on Linux and Mac. If something other than NULL is
///                 passed the default Houdini search paths will be
///                 appended to the end of the path string.
///
/// @param[in]      dso_search_path
///                 The directory where generic DSOs (custom plugins) are
///                 searched for. You can pass NULL here which will
///                 only use the default Houdini DSO search paths. You
///                 can also pass in multiple paths separated by a ";"
///                 on Windows and a ":" on Linux and Mac. If something
///                 other than NULL is passed the default Houdini search
///                 paths will be appended to the end of the path string.
///
/// @param[in]      image_dso_search_path
///                 The directory where image DSOs (custom plugins) are
///                 searched for. You can pass NULL here which will
///                 only use the default Houdini DSO search paths. You
///                 can also pass in multiple paths separated by a ";"
///                 on Windows and a ":" on Linux and Mac. If something
///                 other than NULL is passed the default Houdini search
///                 paths will be appended to the end of the path string.
///
/// @param[in]      audio_dso_search_path
///                 The directory where audio DSOs (custom plugins) are
///                 searched for. You can pass NULL here which will
///                 only use the default Houdini DSO search paths. You
///                 can also pass in multiple paths separated by a ";"
///                 on Windows and a ":" on Linux and Mac. If something
///                 other than NULL is passed the default Houdini search
///                 paths will be appended to the end of the path string.
///
/// [HAPI_Initialize]
HAPI_DECL HAPI_Initialize( const HAPI_Session * session,
                           const HAPI_CookOptions * cook_options,
                           HAPI_Bool use_cooking_thread,
                           int cooking_thread_stack_size,
                           const char * houdini_environment_files,
                           const char * otl_search_path,
                           const char * dso_search_path,
                           const char * image_dso_search_path,
                           const char * audio_dso_search_path );
/// [HAPI_Initialize]

/// @brief  Clean up memory. This will unload all assets and you will
///         need to call ::HAPI_Initialize() again to be able to use any
///         HAPI methods again.
///
///         @note This does NOT release any licenses.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
HAPI_DECL HAPI_Cleanup( const HAPI_Session * session );

// DIAGNOSTICS --------------------------------------------------------------

/// @brief  Gives back a certain environment integers like version number.
///         Note that you do not need a session for this. These constants
///         are hard-coded in all HAPI implementations, including HARC and
///         HAPIL. This should be the first API you call to determine if
///         any future API calls will mismatch implementation.
///
/// @param[in]      int_type
///                 One of ::HAPI_EnvIntType.
///
/// @param[out]     value
///                 Int value.
///
HAPI_DECL HAPI_GetEnvInt( HAPI_EnvIntType int_type, int * value );

/// @brief  Gives back a certain session-specific environment integers
///         like current license type being used.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      int_type
///                 One of ::HAPI_SessionEnvIntType.
///
/// @param[out]     value
///                 Int value.
///
HAPI_DECL HAPI_GetSessionEnvInt( const HAPI_Session * session,
                                 HAPI_SessionEnvIntType int_type,
                                 int * value );

/// @brief  Get environment variable from the server process as an integer.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      variable_name
///                 Name of the environmnet variable.
///
/// @param[out]     value
///                 The int pointer to return the value in.
///
HAPI_DECL HAPI_GetServerEnvInt( const HAPI_Session * session,
                                const char * variable_name,
                                int * value );

/// @brief  Get environment variable from the server process as a string.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      variable_name
///                 Name of the environmnet variable.
///
/// @param[out]     value
///                 The HAPI_StringHandle pointer to return the value in.
///
HAPI_DECL HAPI_GetServerEnvString( const HAPI_Session * session,
                                   const char * variable_name,
                                   HAPI_StringHandle * value );

/// @brief  Provides the number of environment variables that are in
///         the server environment's process
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[out]     env_count
///                 A pointer to an int to return the value in
HAPI_DECL HAPI_GetServerEnvVarCount( const HAPI_Session * session,
                                     int * env_count );

/// @brief  Provides a list of all of the environment variables
///         in the server's process
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[out]     values_array
///                 An ::HAPI_StringHandle array at least the size of length
///
/// @param[in]      start
///                 First index of range. Must be at least @c 0 and at most
///                 @c env_count returned by ::HAPI_GetServerEnvVarCount()
///
/// @param[in]      length
///                 Given @c env_count returned by ::HAPI_GetServerEnvVarCount(),
///                 length should be at least @c 0 and at most <tt>env_count - start.</tt>
HAPI_DECL HAPI_GetServerEnvVarList( const HAPI_Session * session,
                                    HAPI_StringHandle * values_array,
                                    int start,
                                    int length );

/// @brief  Set environment variable for the server process as an integer.
///
///         Note that this may affect other sessions on the same server
///         process. The session parameter is mainly there to identify the
///         server process, not the specific session.
///
///         For in-process sessions, this will affect the current process's
///         environment.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      variable_name
///                 Name of the environmnet variable.
///
/// @param[in]      value
///                 The integer value.
///
HAPI_DECL HAPI_SetServerEnvInt( const HAPI_Session * session,
                                const char * variable_name,
                                int value );

/// @brief  Set environment variable for the server process as a string.
///
///         Note that this may affect other sessions on the same server
///         process. The session parameter is mainly there to identify the
///         server process, not the specific session.
///
///         For in-process sessions, this will affect the current process's
///         environment.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      variable_name
///                 Name of the environmnet variable.
///
/// @param[in]      value
///                 The string value.
///
HAPI_DECL HAPI_SetServerEnvString( const HAPI_Session * session,
                                   const char * variable_name,
                                   const char * value );

/// @brief  Gives back the status code for a specific status type.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      status_type
///                 One of ::HAPI_StatusType.
///
/// @param[out]     status
///                 Actual status code for the status type given. That is,
///                 if you pass in ::HAPI_STATUS_CALL_RESULT as
///                 status_type, you'll get back a ::HAPI_Result for this
///                 argument. If you pass in ::HAPI_STATUS_COOK_STATE
///                 as status_type, you'll get back a ::HAPI_State enum
///                 for this argument.
///
HAPI_DECL HAPI_GetStatus( const HAPI_Session * session,
                          HAPI_StatusType status_type,
                          int * status );

/// @brief  Return length of string buffer storing status string message.
///
///         If called with ::HAPI_STATUS_COOK_RESULT this will actually
///         parse the node networks for the previously cooked asset(s)
///         and aggregate all node errors, warnings, and messages
///         (depending on the @c verbosity level set). Usually this is done
///         just for the last cooked single asset but if you load a whole
///         Houdini scene using ::HAPI_LoadHIPFile() then you'll have
///         multiple "previously cooked assets".
///
///         You MUST call ::HAPI_GetStatusStringBufLength() before calling
///         ::HAPI_GetStatusString() because ::HAPI_GetStatusString() will
///         not return the real status string and instead return a
///         cached version of the string that was created inside
///         ::HAPI_GetStatusStringBufLength(). The reason for this is that
///         the length of the real status string may change between
///         the call to ::HAPI_GetStatusStringBufLength() and the call to
///         ::HAPI_GetStatusString().
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      status_type
///                 One of ::HAPI_StatusType.
///
/// @param[in]      verbosity
///                 Preferred verbosity level.
///
/// @param[out]     buffer_length
///                 Length of buffer char array ready to be filled.
///
HAPI_DECL HAPI_GetStatusStringBufLength( const HAPI_Session * session,
                                         HAPI_StatusType status_type,
                                         HAPI_StatusVerbosity verbosity,
                                         int * buffer_length );

/// @brief  Return status string message.
///
///         You MUST call ::HAPI_GetStatusStringBufLength() before calling
///         ::HAPI_GetStatusString() because ::HAPI_GetStatusString() will
///         not return the real status string and instead return a
///         cached version of the string that was created inside
///         ::HAPI_GetStatusStringBufLength(). The reason for this is that
///         the length of the real status string may change between
///         the call to ::HAPI_GetStatusStringBufLength() and the call to
///         ::HAPI_GetStatusString().
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      status_type
///                 One of ::HAPI_StatusType.
///
/// @param[out]     string_value
///                 Buffer char array ready to be filled.
///
/// @param[in]      length
///                 Length of the string buffer (must match size of
///                 string_value - so including NULL terminator).
///
HAPI_DECL HAPI_GetStatusString( const HAPI_Session * session,
                                HAPI_StatusType status_type,
                                char * string_value,
                                int length );

/// @brief  Compose the cook result string (errors and warnings) of a
///         specific node.
///
///         This will actually parse the node network inside the given
///         node and return ALL errors/warnings/messages of all child nodes,
///         combined into a single string. If you'd like a more narrowed
///         search, call this function on one of the child nodes.
///
///         You MUST call ::HAPI_ComposeNodeCookResult() before calling
///         ::HAPI_GetComposedNodeCookResult() because
///         ::HAPI_GetComposedNodeCookResult() will
///         not return the real result string and instead return a
///         cached version of the string that was created inside
///         ::HAPI_ComposeNodeCookResult(). The reason for this is that
///         the length of the real status string may change between
///         the call to ::HAPI_ComposeNodeCookResult() and the call to
///         ::HAPI_GetComposedNodeCookResult().
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      verbosity
///                 Preferred verbosity level.
///
/// @param[out]     buffer_length
///                 Length of buffer char array ready to be filled.
///
HAPI_DECL HAPI_ComposeNodeCookResult( const HAPI_Session * session,
                                      HAPI_NodeId node_id,
                                      HAPI_StatusVerbosity verbosity,
                                      int * buffer_length );

/// @brief  Return cook result string message on a single node.
///
///         You MUST call ::HAPI_ComposeNodeCookResult() before calling
///         ::HAPI_GetComposedNodeCookResult() because
///         ::HAPI_GetComposedNodeCookResult() will
///         not return the real result string and instead return a
///         cached version of the string that was created inside
///         ::HAPI_ComposeNodeCookResult(). The reason for this is that
///         the length of the real status string may change between
///         the call to ::HAPI_ComposeNodeCookResult() and the call to
///         ::HAPI_GetComposedNodeCookResult().
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[out]     string_value
///                 Buffer char array ready to be filled.
///
/// @param[in]      length
///                 Length of the string buffer (must match size of
///                 string_value - so including NULL terminator).
///
HAPI_DECL HAPI_GetComposedNodeCookResult( const HAPI_Session * session,
                                          char * string_value,
                                          int length );

/// @brief  Recursively check for specific errors by error code on a node.
///
///         Note that checking for errors can be expensive because it checks
///         ALL child nodes within a node and then tries to do a string match
///         for the errors being looked for. This is why such error checking
///         is part of a standalone function and not done during the cooking
///         step.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      errors_to_look_for
///                 The HAPI_ErrorCode error codes (as a bitfield) to look for.
///
/// @param[out]     errors_found
///                 Returned HAPI_ErrorCode bitfield indicating which of the
///                 looked for errors have been found.
///
HAPI_DECL HAPI_CheckForSpecificErrors( const HAPI_Session * session,
                                       HAPI_NodeId node_id,
                                       HAPI_ErrorCodeBits errors_to_look_for,
                                       HAPI_ErrorCodeBits * errors_found );

/// @brief  Get total number of nodes that need to cook in the current
///         session.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[out]     count
///                 Total cook count.
///
HAPI_DECL HAPI_GetCookingTotalCount( const HAPI_Session * session,
                                     int * count );

/// @brief  Get current number of nodes that have already cooked in the
///         current session. Note that this is a very crude approximation
///         of the cooking progress - it may never make it to 100% or it
///         might spend another hour at 100%. Use ::HAPI_GetStatusString
///         to get a better idea of progress if this number gets stuck.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[out]     count
///                 Current cook count.
///
HAPI_DECL HAPI_GetCookingCurrentCount( const HAPI_Session * session,
                                       int * count );

// UTILITY ------------------------------------------------------------------

/// @brief  Converts the transform described by a ::HAPI_TransformEuler
///         struct into a different transform and rotation order.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      transform_in
///                 The transform to be converted.
///
/// @param[in]      rst_order
///                 The desired transform order of the output.
///
/// @param[in]      rot_order
///                 The desired rotation order of the output.
///
/// @param[out]     transform_out
///                 The converted transform.
///
HAPI_DECL HAPI_ConvertTransform( const HAPI_Session * session,
                                 const HAPI_TransformEuler * transform_in,
                                 HAPI_RSTOrder rst_order,
                                 HAPI_XYZOrder rot_order,
                                 HAPI_TransformEuler * transform_out );

/// @brief  Converts a 4x4 matrix into its TRS form.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      matrix
///                 A 4x4 matrix expressed in a 16 element float array.
///
/// @param[in]      rst_order
///                 The desired transform order of the output.
///
/// @param[out]     transform_out
///                 Used for the output.
///
HAPI_DECL HAPI_ConvertMatrixToQuat( const HAPI_Session * session,
                                    const float * matrix,
                                    HAPI_RSTOrder rst_order,
                                    HAPI_Transform * transform_out );

/// @brief  Converts a 4x4 matrix into its TRS form.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      matrix
///                 A 4x4 matrix expressed in a 16 element float array.
///
/// @param[in]      rst_order
///                 The desired transform order of the output.
///
/// @param[in]      rot_order
///                 The desired rotation order of the output.
///
/// @param[out]     transform_out
///                 Used for the output.
///
HAPI_DECL HAPI_ConvertMatrixToEuler( const HAPI_Session * session,
                                     const float * matrix,
                                     HAPI_RSTOrder rst_order,
                                     HAPI_XYZOrder rot_order,
                                     HAPI_TransformEuler * transform_out );

/// @brief  Converts ::HAPI_Transform into a 4x4 transform matrix.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      transform
///                 The ::HAPI_Transform you wish to convert.
///
/// @param[out]     matrix
///                 A 16 element float array that will contain the result.
///
HAPI_DECL HAPI_ConvertTransformQuatToMatrix( const HAPI_Session * session,
                                             const HAPI_Transform * transform,
                                             float * matrix );

/// @brief  Converts ::HAPI_TransformEuler into a 4x4 transform matrix.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      transform
///                 The ::HAPI_TransformEuler you wish to convert.
///
/// @param[out]     matrix
///                 A 16 element float array that will contain the result.
///
HAPI_DECL HAPI_ConvertTransformEulerToMatrix(
                                    const HAPI_Session * session,
                                    const HAPI_TransformEuler * transform,
                                    float * matrix );

/// @brief  Acquires or releases the Python interpreter lock. This is
///         needed if HAPI is called from Python and HAPI is in threaded
///         mode (see ::HAPI_Initialize()).
///
///         The problem arises when async functions like
///         ::HAPI_CreateNode() may start a cooking thread that
///         may try to run Python code. That is, we would now have
///         Python running on two different threads - something not
///         allowed by Python by default.
///
///         We need to tell Python to explicitly "pause" the Python state
///         on the client thread while we run Python in our cooking thread.
///
///         You must call this function first with locked == true before
///         any async HAPI call. Then, after the async call finished,
///         detected via calls to ::HAPI_GetStatus(), call this method
///         again to release the lock with locked == false.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      locked
///                 True will acquire the interpreter lock to use it for
///                 the HAPI cooking thread. False will release the lock
///                 back to the client thread.
///
HAPI_DECL HAPI_PythonThreadInterpreterLock( const HAPI_Session * session,
                                            HAPI_Bool locked );

// STRINGS ------------------------------------------------------------------

/// @brief  Gives back the string length of the string with the
///         given handle.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      string_handle
///                 Handle of the string to query.
///
/// @param[out]     buffer_length
///                 Buffer length of the queried string (including NULL
///                 terminator).
///
HAPI_DECL HAPI_GetStringBufLength( const HAPI_Session * session,
                                   HAPI_StringHandle string_handle,
                                   int * buffer_length );

/// @brief  Gives back the string value of the string with the
///         given handle.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      string_handle
///                 Handle of the string to query.
///
/// @param[out]     string_value
///                 Actual string value (character array).
///
/// @param[in]      length
///                 Length of the string buffer (must match size of
///                 string_value - so including NULL terminator).
///
HAPI_DECL HAPI_GetString( const HAPI_Session * session,
                          HAPI_StringHandle string_handle,
                          char * string_value,
                          int length );

/// @brief  Adds the given string to the string table and returns 
///         the handle. It is the responsibility of the caller to
///         manage access to the string. The intended use for custom strings
///         is to allow structs that reference strings to be passed in to HAPI
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      string_value
///                 Actual string value (character array).
///
/// @param[out]     handle_value
///                 Handle of the string that was added
///
HAPI_DECL HAPI_SetCustomString( const HAPI_Session * session,
                          const char * string_value,
                          int *handle_value);

/// @brief  Removes the specified string from the server
///         and invalidates the handle
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]     string_handle
///                 Handle of the string that was added
///
HAPI_DECL HAPI_RemoveCustomString( const HAPI_Session * session,
                          const int string_handle);

/// @brief  Gives back the length of the buffer needed to hold
///         all the values null-separated for the given string 
///         handles.  Used with HAPI_GetStringBatch.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      string_handle_array
///                 Array of string handles to be read.
///
/// @param[in]      string_handle_count
///                 Length of string_handle_array
///
/// @param[out]     string_buffer_size
///                 Buffer length required for subsequent call to
///                 HAPI_GetStringBatch to hold all the given 
///                 string values null-terminated
///
HAPI_DECL HAPI_GetStringBatchSize(const HAPI_Session * session,
                                  const int * string_handle_array,
                                  int string_handle_count,
                                  int* string_buffer_size);

/// @brief  Gives back the values of the given string handles.
///         The given char array is filled with null-separated 
///         values, and the final value is null-terminated.
///         Used with HAPI_GetStringBatchSize.  Using this function
///         instead of repeated calls to HAPI_GetString can be more
///         more efficient for a large number of strings.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[out]     char_array
///                 Array of characters to hold string values.
///
/// @param[in]      char_array_length
///                 Length of char_array.  Must be large enough to hold
///                 all the string values including null separators.
///
HAPI_DECL HAPI_GetStringBatch(const HAPI_Session * session,
                              char * char_array,
                              int char_array_length);


// TIME ---------------------------------------------------------------------

/// @brief  Gets the global time of the scene. All API calls deal with
///         this time to cook.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[out]     time
///                 Time as a float in seconds.
///
HAPI_DECL HAPI_GetTime( const HAPI_Session * session, float * time );

/// @brief  Sets the global time of the scene. All API calls will deal
///         with this time to cook.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      time
///                 Time as a float in seconds.
///
HAPI_DECL HAPI_SetTime( const HAPI_Session * session, float time );

/// @brief  Gets the current global timeline options.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      timeline_options
///                 The global timeline options struct.
///
HAPI_DECL HAPI_GetTimelineOptions( const HAPI_Session * session,
                                   HAPI_TimelineOptions * timeline_options );

/// @brief  Sets the global timeline options.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      timeline_options
///                 The global timeline options struct.
///
HAPI_DECL HAPI_SetTimelineOptions(
                            const HAPI_Session * session,
                            const HAPI_TimelineOptions * timeline_options );

// ASSETS -------------------------------------------------------------------

/// @brief  Loads a Houdini asset library (OTL) from a .otl file.
///         It does NOT create anything inside the Houdini scene.
///
///         @note This is when we actually check for valid licenses.
///
///         The next step is to call ::HAPI_GetAvailableAssetCount()
///         to get the number of assets contained in the library using the
///         returned library_id. Then call ::HAPI_GetAvailableAssets()
///         to get the list of available assets by name. Use the asset
///         names with ::HAPI_CreateNode() to actually create
///         one of these nodes in the Houdini scene and get back
///         an asset_id.
///
///         @note The HIP file saved using ::HAPI_SaveHIPFile() will only
///             have an absolute path reference to the loaded OTL meaning
///             that if the OTL is moved or renamed the HIP file won't
///             load properly. It also means that if you change the OTL
///             using the saved HIP scene the same OTL file will change
///             as the one used with Houdini Engine.
///             See @ref HAPI_Fundamentals_SavingHIPFile.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      file_path
///                 Absolute path to the .otl file.
///
/// @param[in]      allow_overwrite
///                 With this true, if the library file being loaded
///                 contains asset definitions that have already been
///                 loaded they will overwrite the existing definitions.
///                 Otherwise, a library containing asset definitions that
///                 already exist will fail to load, returning a
///                 ::HAPI_Result of
///                 ::HAPI_RESULT_ASSET_DEF_ALREADY_LOADED.
///
/// @param[out]     library_id
///                 Newly loaded otl id to be used with
///                 ::HAPI_GetAvailableAssetCount() and
///                 ::HAPI_GetAvailableAssets().
///
HAPI_DECL HAPI_LoadAssetLibraryFromFile( const HAPI_Session * session,
                                         const char * file_path,
                                         HAPI_Bool allow_overwrite,
                                         HAPI_AssetLibraryId* library_id );

/// @brief  Loads a Houdini asset library (OTL) from memory.
///         It does NOT create anything inside the Houdini scene.
///
///         @note This is when we actually check for valid licenses.
///
///         Please note that the performance benefit of loading a library
///         from memory are negligible at best. Due to limitations of
///         Houdini's library manager, there is still some disk access
///         and file writes because every asset library needs to be
///         saved to a real file. Use this function only as a convenience
///         if you already have the library file in memory and don't wish
///         to have to create your own temporary library file and then
///         call ::HAPI_LoadAssetLibraryFromFile().
///
///         The next step is to call ::HAPI_GetAvailableAssetCount()
///         to get the number of assets contained in the library using the
///         returned library_id. Then call ::HAPI_GetAvailableAssets()
///         to get the list of available assets by name. Use the asset
///         names with ::HAPI_CreateNode() to actually create
///         one of these nodes in the Houdini scene and get back
///         an asset_id.
///
///         @note The saved HIP file using ::HAPI_SaveHIPFile() will
///             @a contain the OTL loaded as part of its @b Embedded OTLs.
///             This means that you can safely move or rename the original
///             OTL file and the HIP will continue to work but if you make
///             changes to the OTL while using the saved HIP the changes
///             won't be saved to the original OTL.
///             See @ref HAPI_Fundamentals_SavingHIPFile.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      library_buffer
///                 The memory buffer containing the asset definitions
///                 in the same format as a standard Houdini .otl file.
///
/// @param[in]      library_buffer_length
///                 The size of the OTL memory buffer.
///
/// @param[in]      allow_overwrite
///                 With this true, if the library file being loaded
///                 contains asset definitions that have already been
///                 loaded they will overwrite the existing definitions.
///                 Otherwise, a library containing asset definitions that
///                 already exist will fail to load, returning a
///                 ::HAPI_Result of
///                 ::HAPI_RESULT_ASSET_DEF_ALREADY_LOADED.
///
/// @param[out]     library_id
///                 Newly loaded otl id to be used with
///                 ::HAPI_GetAvailableAssetCount() and
///                 ::HAPI_GetAvailableAssets().
///
HAPI_DECL HAPI_LoadAssetLibraryFromMemory( const HAPI_Session * session,
                                           const char * library_buffer,
                                           int library_buffer_length,
                                           HAPI_Bool allow_overwrite,
                                           HAPI_AssetLibraryId * library_id );

/// @brief  Get the number of assets contained in an asset library.
///         You should call ::HAPI_LoadAssetLibraryFromFile() prior to
///         get a library_id.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      library_id
///                 Returned by ::HAPI_LoadAssetLibraryFromFile().
///
/// @param[out]     asset_count
///                 The number of assets contained in this asset library.
///
HAPI_DECL HAPI_GetAvailableAssetCount( const HAPI_Session * session,
                                       HAPI_AssetLibraryId library_id,
                                       int * asset_count );

/// @brief  Get the names of the assets contained in an asset library.
///
///         The asset names will contain additional information about
///         the type of asset, namespace, and version, along with the
///         actual asset name. For example, if you have an Object type
///         asset, in the "hapi" namespace, of version 2.0, named
///         "foo", the asset name returned here will be:
///         hapi::Object/foo::2.0
///
///         However, you should not need to worry about this detail. Just
///         pass this string directly to ::HAPI_CreateNode() to
///         create the node. You can then get the pretty name
///         using ::HAPI_GetAssetInfo().
///
///         You should call ::HAPI_LoadAssetLibraryFromFile() prior to
///         get a library_id. Then, you should call
///         ::HAPI_GetAvailableAssetCount() to get the number of assets to
///         know how large of a string handles array you need to allocate.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      library_id
///                 Returned by ::HAPI_LoadAssetLibraryFromFile().
///
/// @param[out]     asset_names_array
///                 Array of string handles (integers) that should be
///                 at least the size of asset_count.
///
/// @param[out]     asset_count
///                 Should be the same or less than the value returned by
///                 ::HAPI_GetAvailableAssetCount().
///
HAPI_DECL HAPI_GetAvailableAssets( const HAPI_Session * session,
                                   HAPI_AssetLibraryId library_id,
                                   HAPI_StringHandle * asset_names_array,
                                   int asset_count );

/// @brief  Fill an asset_info struct from a node.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[out]     asset_info
///                 Returned ::HAPI_AssetInfo struct.
///
HAPI_DECL HAPI_GetAssetInfo( const HAPI_Session * session,
                             HAPI_NodeId node_id,
                             HAPI_AssetInfo * asset_info );

/// @brief  Interrupt a cook or load operation.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
HAPI_DECL HAPI_Interrupt( const HAPI_Session * session );

// HIP FILES ----------------------------------------------------------------

/// @brief  Loads a .hip file into the main Houdini scene.
///
///         @note In threaded mode, this is an _async call_!
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      file_name
///                 Absolute path to the .hip file to load.
///
/// @param[in]      cook_on_load
///                 Set to true if you wish the nodes to cook as soon
///                 as they are created. Otherwise, you will have to
///                 call ::HAPI_CookNode() explicitly for each after you
///                 call this function.
///
HAPI_DECL HAPI_LoadHIPFile( const HAPI_Session * session,
                            const char * file_name,
                            HAPI_Bool cook_on_load );

/// @brief  Saves a .hip file of the current Houdini scene.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      file_path
///                 Absolute path to the .hip file to save to.
///
/// @param[in]      lock_nodes
///                 Specify whether to lock all SOP nodes before saving
///                 the scene file. This way, when you load the scene
///                 file you can see exactly the state of each SOP at
///                 the time it was saved instead of relying on the
///                 re-cook to accurately reproduce the state. It does,
///                 however, take a lot more space and time locking all
///                 nodes like this.
///
HAPI_DECL HAPI_SaveHIPFile( const HAPI_Session * session,
                            const char * file_path,
                            HAPI_Bool lock_nodes );

// NODES --------------------------------------------------------------------

/// @brief  Determine if your instance of the node actually still exists
///         inside the Houdini scene. This is what can be used to
///         determine when the Houdini scene needs to be re-populated
///         using the host application's instances of the nodes.
///         Note that this function will ALWAYS return
///         ::HAPI_RESULT_SUCCESS.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      unique_node_id
///                 The unique node id from
///                 ::HAPI_NodeInfo::uniqueHoudiniNodeId.
///
/// @param[out]     answer
///                 Answer to the question.
///
HAPI_DECL HAPI_IsNodeValid( const HAPI_Session * session,
                            HAPI_NodeId node_id,
                            int unique_node_id,
                            HAPI_Bool * answer );

/// @brief  Fill an ::HAPI_NodeInfo struct.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[out]     node_info
///                 Return value - contains things like asset id.
///
HAPI_DECL HAPI_GetNodeInfo( const HAPI_Session * session,
                            HAPI_NodeId node_id,
                            HAPI_NodeInfo * node_info );

/// @brief  Get the node absolute path in the Houdini node network or a
///         relative path any other node.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      relative_to_node_id
///                 Set this to -1 to get the absolute path of the node_id.
///                 Otherwise, the path will be relative to this node id.
///
/// @param[out]     path
///                 The returned path string, valid until the next call to
///                 this function.
///
HAPI_DECL HAPI_GetNodePath( const HAPI_Session * session,
                            HAPI_NodeId node_id,
                            HAPI_NodeId relative_to_node_id,
                            HAPI_StringHandle * path );

/// @brief  Get the root node of a particular network type (ie. OBJ).
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_type
///                 The node network type.
///
/// @param[out]     node_id
///                 The node id of the root node network.
///
HAPI_DECL HAPI_GetManagerNodeId( const HAPI_Session * session,
                                 HAPI_NodeType node_type,
                                 HAPI_NodeId * node_id );

/// @brief  Compose a list of child nodes based on given filters.
///
///         This function will only compose the list of child nodes. It will
///         not return this list. After your call to this function, call
///         HAPI_GetComposedChildNodeList() to get the list of child node ids.
///
///         Note: When looking for all Display SOP nodes using this function,
///         and using recursive mode, the recursion will stop as soon as a
///         display SOP is found within each OBJ geometry network. It is
///         almost never useful to get a list of ALL display SOP nodes
///         recursively as they would all containt the same geometry. Even so,
///         this special case only comes up if the display SOP itself is a
///         subnet.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      parent_node_id
///                 The node id of the parent node.
///
/// @param[in]      node_type_filter
///                 The node type by which to filter the children.
///
/// @param[in]      node_flags_filter
///                 The node flags by which to filter the children.
///
/// @param[in]      recursive
///                 Whether or not to compose the list recursively.
///
/// @param[out]     count
///                 The number of child nodes composed. Use this as the
///                 argument to ::HAPI_GetComposedChildNodeList().
///
HAPI_DECL HAPI_ComposeChildNodeList( const HAPI_Session * session,
                                     HAPI_NodeId parent_node_id,
                                     HAPI_NodeTypeBits node_type_filter,
                                     HAPI_NodeFlagsBits node_flags_filter,
                                     HAPI_Bool recursive,
                                     int * count );

/// @brief  Get the composed list of child node ids from the previous call
///         to HAPI_ComposeChildNodeList().
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      parent_node_id
///                 The node id of the parent node.
///
/// @param[out]     child_node_ids_array
///                 The array of ::HAPI_NodeId for the child nodes.
///
/// @param[in]      count
///                 The number of children in the composed list. MUST match
///                 the count returned by HAPI_ComposeChildNodeList().
///
HAPI_DECL HAPI_GetComposedChildNodeList( const HAPI_Session * session,
                                         HAPI_NodeId parent_node_id,
                                         HAPI_NodeId * child_node_ids_array,
                                         int count );

/// @brief  Create a node inside a node network. Nodes created this way
///         will have their ::HAPI_NodeInfo::createdPostAssetLoad set
///         to true.
///
///         @note In threaded mode, this is an _async call_!
///
///         @note This is also when we actually check for valid licenses.
///
///         This API will invoke the cooking thread if threading is
///         enabled. This means it will return immediately with a call
///         result of ::HAPI_RESULT_SUCCESS, even if fed garbage. Use
///         the status and cooking count APIs under DIAGNOSTICS to get
///         a sense of the progress. All other API calls will block
///         until the creation (and, optionally, the first cook)
///         of the node has finished.
///
///         Also note that the cook result won't be of type
///         ::HAPI_STATUS_CALL_RESULT like all calls (including this one).
///         Whenever the threading cook is done it will fill the
///         @a cook result which is queried using
///         ::HAPI_STATUS_COOK_RESULT.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      parent_node_id
///                 The parent node network's node id or -1 if the parent
///                 network is the manager (top-level) node. In that case,
///                 the manager must be identified by the table name in the
///                 operator_name.
///
/// @param[in]      operator_name
///                 The name of the node operator type.
///
///                 If you passed parent_node_id == -1, then the operator_name
///                 has to include the table name (ie. Object/ or Sop/).
///                 This is the common case for when creating asset nodes
///                 from a loaded asset library. In that case, just pass
///                 whatever ::HAPI_GetAvailableAssets() returns.
///
///                 If you have a parent_node_id then you should
///                 include only the namespace, name, and version.
///
///                 For example, lets say you have an Object type asset, in
///                 the "hapi" namespace, of version 2.0, named "foo". If
///                 you pass parent_node_id == -1, then set the operator_name
///                 as "Object/hapi::foo::2.0". Otherwise, if you have a valid
///                 parent_node_id, then just pass operator_name as
///                 "hapi::foo::2.0".
///
/// @param[in]      node_label
///                 (Optional) The label of the newly created node.
///
/// @param[in]      cook_on_creation
///                 Set whether the node should cook once created or not.
///
/// @param[out]     new_node_id
///                 The returned node id of the just-created node.
///
HAPI_DECL HAPI_CreateNode( const HAPI_Session * session,
                           HAPI_NodeId parent_node_id,
                           const char * operator_name,
                           const char * node_label,
                           HAPI_Bool cook_on_creation,
                           HAPI_NodeId * new_node_id );

/// @brief  Creates a simple geometry SOP node that can accept geometry input.
///         This will create a dummy OBJ node with a Null SOP inside that
///         you can set the geometry of using the geometry SET APIs.
///         You can then connect this node to any other node as a geometry
///         input.
///
///         Note that when saving the Houdini scene using
///         ::HAPI_SaveHIPFile() the nodes created with this
///         method will be green and will start with the name "input".
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[out]     node_id
///                 Newly created node's id. Use ::HAPI_GetNodeInfo()
///                 to get more information about the node.
///
/// @param[in]      name
///                 Give this input node a name for easy debugging.
///                 The node's parent OBJ node and the Null SOP node will both
///                 get this given name with "input_" prepended.
///                 You can also pass NULL in which case the name will
///                 be "input#" where # is some number.
///
HAPI_DECL HAPI_CreateInputNode( const HAPI_Session * session,
                                HAPI_NodeId * node_id,
                                const char * name );

/// @brief  Creates the required node hierarchy needed for Heightfield inputs.
///
///         Note that when saving the Houdini scene using
///         ::HAPI_SaveHIPFile() the nodes created with this
///         method will be green and will start with the name "input".
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      parent_node_id
///                 The parent node network's node id or -1 if the parent
///                 network is the manager (top-level) node. In that case,
///                 the manager must be identified by the table name in the
///                 operator_name.
///
/// @param[in]      name
///                 Give this input node a name for easy debugging.
///                 The node's parent OBJ node and the Null SOP node will both
///                 get this given name with "input_" prepended.
///                 You can also pass NULL in which case the name will
///                 be "input#" where # is some number.
///
/// @param[in]      xsize
///                 size of the heightfield in X
///
/// @param[in]      ysize
///                 size of the heightfield in y
///
/// @param[in]      voxelsize
///                 Size of the voxel
///
/// @param[out]     heightfield_node_id
///                 Newly created node id for the Heightfield node.
///                 Use ::HAPI_GetNodeInfo() to get more information about
///                 the node.
///
/// @param[out]     height_node_id
///                 Newly created node id for the height volume.
///                 Use ::HAPI_GetNodeInfo() to get more information about the node.
///
/// @param[out]     mask_node_id
///                 Newly created node id for the mask volume.
///                 Use ::HAPI_GetNodeInfo() to get more information about the
///                 node.
///
/// @param[out]     merge_node_id
///                 Newly created merge node id. 
///                 The merge node can be used to connect additional input masks.
///                 Use ::HAPI_GetNodeInfo() to get more information about the node.
///
HAPI_DECL HAPI_CreateHeightfieldInputNode(  const HAPI_Session * session,
                                            HAPI_NodeId parent_node_id,
                                            const char * name,
                                            int xsize,
                                            int ysize,
                                            float voxelsize,
                                            HAPI_NodeId * heightfield_node_id,
                                            HAPI_NodeId * height_node_id,
                                            HAPI_NodeId * mask_node_id,
                                            HAPI_NodeId * merge_node_id );

/// @brief  Creates a volume input node that can be used with Heightfields
///
///         Note that when saving the Houdini scene using
///         ::HAPI_SaveHIPFile() the nodes created with this
///         method will be green and will start with the name "input".
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      parent_node_id
///                 The parent node network's node id or -1 if the parent
///                 network is the manager (top-level) node. In that case,
///                 the manager must be identified by the table name in the
///                 operator_name.
///
/// @param[out]     new_node_id
///                 Newly created node id for the volume.
///                 Use ::HAPI_GetNodeInfo() to get more information about the
///                 node.
///
/// @param[in]      name
///                 The name of the volume to create.
///                 You can also pass NULL in which case the name will
///                 be "input#" where # is some number.
///
/// @param[in]      xsize
///                 size of the heightfield in X
///
/// @param[in]      ysize
///                 size of the heightfield in y
///
/// @param[in]      voxelsize
///                 Size of the voxel
///
HAPI_DECL HAPI_CreateHeightfieldInputVolumeNode(    const HAPI_Session * session,
                                                    HAPI_NodeId parent_node_id,
                                                    HAPI_NodeId * new_node_id,
                                                    const char * name,
                                                    int xsize,
                                                    int ysize,
                                                    float voxelsize );

/// @brief  Initiate a cook on this node. Note that this may trigger
///         cooks on other nodes if they are connected.
///
///         @note In threaded mode, this is an _async call_!
///
///         This API will invoke the cooking thread if threading is
///         enabled. This means it will return immediately. Use
///         the status and cooking count APIs under DIAGNOSTICS to get
///         a sense of the progress. All other API calls will block
///         until the cook operation has finished.
///
///         Also note that the cook result won't be of type
///         ::HAPI_STATUS_CALL_RESULT like all calls (including this one).
///         Whenever the threading cook is done it will fill the
///         @a cook result which is queried using
///         ::HAPI_STATUS_COOK_RESULT.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      cook_options
///                 The cook options. Pass in NULL to use the global
///                 cook options that you specified when calling
///                 ::HAPI_Initialize().
///
HAPI_DECL HAPI_CookNode( const HAPI_Session * session,
                         HAPI_NodeId node_id,
                         const HAPI_CookOptions * cook_options );

/// @brief  Delete a node from a node network. Only nodes with their
///         ::HAPI_NodeInfo::createdPostAssetLoad set to true can be
///         deleted this way.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node to delete.
///
HAPI_DECL HAPI_DeleteNode( const HAPI_Session * session,
                           HAPI_NodeId node_id );

/// @brief  Rename a node that you created. Only nodes with their
///         ::HAPI_NodeInfo::createdPostAssetLoad set to true can be
///         deleted this way.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node to delete.
///
/// @param[in]      new_name
///                 The new node name.
///
HAPI_DECL HAPI_RenameNode( const HAPI_Session * session,
                           HAPI_NodeId node_id,
                           const char * new_name );

/// @brief  Connect two nodes together.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node whom's input to connect to.
///
/// @param[in]      input_index
///                 The input index. Should be between 0 and the
///                 to_node's ::HAPI_NodeInfo::inputCount - 1.
///
/// @param[in]      node_id_to_connect
///                 The node to connect to node_id's input.
///
/// @param[in]	    output_index
///                 The output index. Should be between 0 and the
///                 to_node's ::HAPI_NodeInfo::outputCount - 1.
///
HAPI_DECL HAPI_ConnectNodeInput( const HAPI_Session * session,
                                 HAPI_NodeId node_id,
                                 int input_index,
                                 HAPI_NodeId node_id_to_connect,
                                 int output_index );

/// @brief  Disconnect a node input.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node whom's input to disconnect.
///
/// @param[in]      input_index
///                 The input index. Should be between 0 and the
///                 to_node's ::HAPI_NodeInfo::inputCount - 1.
///
HAPI_DECL HAPI_DisconnectNodeInput( const HAPI_Session * session,
                                    HAPI_NodeId node_id,
                                    int input_index );

/// @brief  Query which node is connected to another node's input.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_to_query
///                 The node to query.
///
/// @param[in]      input_index
///                 The input index. Should be between 0 and the
///                 to_node's ::HAPI_NodeInfo::inputCount - 1.
///
/// @param[out]     connected_node_id
///                 The node id of the connected node to this input. If
///                 nothing is connected then -1 will be returned.
///
HAPI_DECL HAPI_QueryNodeInput( const HAPI_Session * session,
                               HAPI_NodeId node_to_query,
                               int input_index,
                               HAPI_NodeId * connected_node_id );

/// @brief  Get the name of an node's input. This function will return
///         a string handle for the name which will be valid (persist)
///         until the next call to this function.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      input_idx
///                 Input index of the asset.
///
/// @param[out]     name
///                 Input name string handle return value - valid until
///                 the next call to this function.
///
HAPI_DECL HAPI_GetNodeInputName( const HAPI_Session * session,
                                 HAPI_NodeId node_id,
                                 int input_idx,
                                 HAPI_StringHandle * name );

/// @brief  Disconnect all of the node's output connections at the output index.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node whom's outputs to disconnect.
///
/// @param[in]      output_index
///                 The output index. Should be between 0 and the
///                 to_node's ::HAPI_NodeInfo::outputCount.
///
HAPI_DECL HAPI_DisconnectNodeOutputsAt( const HAPI_Session *session,
                                        HAPI_NodeId node_id,
                                        int output_index );

/// @brief  Get the number of nodes currently connected to the given node at 
///	    the output index.
///
///         Use the @c count returned by this function to get the
///         ::HAPI_NodeIds of connected nodes using
///         ::HAPI_QueryNodeOutputConnectedNodes().
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      output_idx
///                 The output index. Should be between 0 and the
///                 to_node's ::HAPI_NodeInfo::outputCount.
///
/// @param[in]      into_subnets
///                 Whether to search by diving into subnets.
///
/// @param[in]      through_dots
///                 Whether to search through dots.
///
/// @param[out]     connected_count
///                 The number of nodes currently connected to this node at 
///                 given output index. Use this count with a call to
///                 ::HAPI_QueryNodeOutputConnectedNodes() to get list of 
///                 connected nodes.
///
HAPI_DECL HAPI_QueryNodeOutputConnectedCount( const HAPI_Session *session,
                                              HAPI_NodeId node_id, 
                                              int output_idx,
                                              HAPI_Bool into_subnets, 
                                              HAPI_Bool through_dots,
                                              int * connected_count );

/// @brief  Get the ids of nodes currently connected to the given node
///	    at the output index.
///
///         Use the @c connected_count returned by 
///	    ::HAPI_QueryNodeOutputConnectedCount().
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      output_idx
///                 The output index. Should be between 0 and the
///                 to_node's ::HAPI_NodeInfo::outputCount.
///
/// @param[in]      into_subnets
///                 Whether to search by diving into subnets.
///
/// @param[in]      through_dots
///                 Whether to search through dots.
///
/// @param[out]     connected_node_ids
///		    Array of ::HAPI_NodeId at least the size of @c length.
///
/// @param[in]      start
///                 At least @c 0 and at most @c connected_count returned by
///                 ::HAPI_QueryNodeOutputConnectedCount().
///
/// @param[in]      length
///                 Given @c connected_count returned by
///                 ::HAPI_QueryNodeOutputConnectedCount(), @c length should 
///                 be at least @c 0 and at most <tt>connected_count - start</tt>.
///
HAPI_DECL HAPI_QueryNodeOutputConnectedNodes( const HAPI_Session *session,
                                             HAPI_NodeId node_id, 
                                             int output_idx, 
                                             HAPI_Bool into_subnets, 
                                             HAPI_Bool through_dots,
                                             HAPI_NodeId * connected_node_ids,
                                             int start, int length );

/// @brief  Get the name of an node's output. This function will return
///         a string handle for the name which will be valid (persist)
///         until the next call to this function.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      output_idx
///                 The output index. Should be between 0 and the
///                 to_node's ::HAPI_NodeInfo::outputCount.
///
/// @param[out]     name
///                 Output name string handle return value - valid until
///                 the next call to this function.
///
HAPI_DECL HAPI_GetNodeOutputName( const HAPI_Session * session,
                                  HAPI_NodeId node_id,
                                  int output_idx,
                                  HAPI_StringHandle * name );

// PARAMETERS ---------------------------------------------------------------

/// @brief  Fill an array of ::HAPI_ParmInfo structs with parameter
///         information from the asset instance node.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[out]     parm_infos_array
///                 Array of ::HAPI_ParmInfo at least the size of
///                 length.
///
/// @param[in]      start
///                 First index of range. Must be at least 0 and at
///                 most ::HAPI_NodeInfo::parmCount - 1.
///
/// @param[in]      length
///                 Must be at least 0 and at most
///                 ::HAPI_NodeInfo::parmCount - start.
///
HAPI_DECL HAPI_GetParameters( const HAPI_Session * session,
                              HAPI_NodeId node_id,
                              HAPI_ParmInfo * parm_infos_array,
                              int start, int length );

/// @brief  Get the parm info of a parameter by parm id.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      parm_id
///                 The parm id.
///
/// @param[out]     parm_info
///                 The returned parm info.
///
HAPI_DECL HAPI_GetParmInfo( const HAPI_Session * session,
                            HAPI_NodeId node_id,
                            HAPI_ParmId parm_id,
                            HAPI_ParmInfo * parm_info );

/// @brief  All parameter APIs require a ::HAPI_ParmId but if you know the
///         parameter you wish to operate on by name than you can use
///         this function to get its ::HAPI_ParmId. If the parameter with
///         the given name is not found the parameter id returned
///         will be -1.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      parm_name
///                 The parm name.
///
/// @param[out]     parm_id
///                 The return value. The parameter's ::HAPI_ParmId. If
///                 the parameter with the given name is not found the
///                 parameter id returned will be -1.
///
HAPI_DECL HAPI_GetParmIdFromName( const HAPI_Session * session,
                                  HAPI_NodeId node_id,
                                  const char * parm_name,
                                  HAPI_ParmId * parm_id );

/// @brief  Get the parm info of a parameter by name.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      parm_name
///                 The parm name.
///
/// @param[out]     parm_info
///                 The returned parm info.
///
HAPI_DECL HAPI_GetParmInfoFromName( const HAPI_Session * session,
                                    HAPI_NodeId node_id,
                                    const char * parm_name,
                                    HAPI_ParmInfo * parm_info );

/// @brief  Get the tag name on a parameter given an index.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      parm_id
///                 The parm id.
///
/// @param[in]      tag_index
///                 The tag index, which should be between 0 and
///                 ::HAPI_ParmInfo::tagCount - 1.
///
/// @param[out]     tag_name
///                 The returned tag name. This string handle will be valid
///                 until another call to ::HAPI_GetParmTagName().
///
HAPI_DECL HAPI_GetParmTagName( const HAPI_Session * session,
                               HAPI_NodeId node_id,
                               HAPI_ParmId parm_id,
                               int tag_index,
                               HAPI_StringHandle * tag_name );

/// @brief  Get the tag value on a parameter given the tag name.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      parm_id
///                 The parm id.
///
/// @param[in]      tag_name
///                 The tag name, either known or returned by
///                 ::HAPI_GetParmTagName().
///
/// @param[out]     tag_value
///                 The returned tag value. This string handle will be valid
///                 until another call to ::HAPI_GetParmTagValue().
///
HAPI_DECL HAPI_GetParmTagValue( const HAPI_Session * session,
                                HAPI_NodeId node_id,
                                HAPI_ParmId parm_id,
                                const char * tag_name,
                                HAPI_StringHandle * tag_value );

/// @brief  See if a parameter has a specific tag.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      parm_id
///                 The parm id.
///
/// @param[in]      tag_name
///                 The tag name to look for.
///
/// @param[out]     has_tag
///                 True if the tag exists on the parameter, false otherwise.
///
HAPI_DECL HAPI_ParmHasTag( const HAPI_Session * session,
                           HAPI_NodeId node_id,
                           HAPI_ParmId parm_id,
                           const char * tag_name,
                           HAPI_Bool * has_tag );

/// @brief  See if a parameter has an expression
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      parm_name
///                 The parm name.
///
/// @param[in]      index
///                 The parm index.
///
/// @param[out]     has_expression
///                 True if an expression exists on the parameter, false otherwise.
///
HAPI_DECL HAPI_ParmHasExpression( const HAPI_Session * session,
                           HAPI_NodeId node_id,
			   const char * parm_name,
                           int index,
                           HAPI_Bool * has_expression );

/// @brief  Get the first parm with a specific, ideally unique, tag on it.
///         This is particularly useful for getting the ogl parameters on a
///         material node.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      tag_name
///                 The tag name to look for.
///
/// @param[out]     parm_id
///                 The returned parm id. This will be -1 if no parm was found
///                 with this tag.
///
HAPI_DECL HAPI_GetParmWithTag( const HAPI_Session * session,
                               HAPI_NodeId node_id,
                               const char * tag_name,
                               HAPI_ParmId * parm_id );

/// @brief  Get single integer or float parm expression by name
///         or Null string if no expression is present
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      parm_name
///                 The parm name.
///
/// @param[in]      index
///                 Index within the parameter's values tuple.
///
/// @param[out]     value
///                 The returned string value.
///
HAPI_DECL HAPI_GetParmExpression( const HAPI_Session * session,
                                HAPI_NodeId node_id,
                                const char * parm_name,
                                int index,
                                HAPI_StringHandle * value );

/// @brief  Revert single parm by name to default
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      parm_name
///                 The parm name.
///
/// @param[in]      index
///                 Index within the parameter's values tuple.
///
HAPI_DECL HAPI_RevertParmToDefault( const HAPI_Session * session,
                                HAPI_NodeId node_id,
                                const char * parm_name,
                                int index);

/// @brief  Revert all instances of the parm by name to defaults
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      parm_name
///                 The parm name.
///
HAPI_DECL HAPI_RevertParmToDefaults( const HAPI_Session * session,
                                HAPI_NodeId node_id,
                                const char * parm_name);

/// @brief  Set (push) an expression string. We can only set a single value at
///         a time because we want to avoid fixed size string buffers.
///
///         @note Regardless of the value, when calling this function
///         on a parameter, if that parameter has a callback function
///         attached to it, that callback function will be called. For
///         example, if the parameter is a button the button will be
///         pressed.
///
///         @note In threaded mode, this is an _async call_!
///
///         This API will invoke the cooking thread if threading is
///         enabled. This means it will return immediately. Use
///         the status and cooking count APIs under DIAGNOSTICS to get
///         a sense of the progress. All other API calls will block
///         until the cook operation has finished.
///
///         Also note that the cook result won't be of type
///         ::HAPI_STATUS_CALL_RESULT like all calls (including this one).
///         Whenever the threading cook is done it will fill the
///         @a cook result which is queried using
///         ::HAPI_STATUS_COOK_RESULT.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      value
///                 The expression string.
///
/// @param[in]      parm_id
///                 Parameter id of the parameter being updated.
///
/// @param[in]      index
///                 Index within the parameter's values tuple.
///
HAPI_DECL HAPI_SetParmExpression( const HAPI_Session * session,
                                   HAPI_NodeId node_id,
                                   const char * value,
                                   HAPI_ParmId parm_id, int index );

/// @brief  Remove the expression string, leaving the value of the
///         parm at the current value of the expression
///
///         @note Regardless of the value, when calling this function
///         on a parameter, if that parameter has a callback function
///         attached to it, that callback function will be called. For
///         example, if the parameter is a button the button will be
///         pressed.
///
///         @note In threaded mode, this is an _async call_!
///
///         This API will invoke the cooking thread if threading is
///         enabled. This means it will return immediately. Use
///         the status and cooking count APIs under DIAGNOSTICS to get
///         a sense of the progress. All other API calls will block
///         until the cook operation has finished.
///
///         Also note that the cook result won't be of type
///         ::HAPI_STATUS_CALL_RESULT like all calls (including this one).
///         Whenever the threading cook is done it will fill the
///         @a cook result which is queried using
///         ::HAPI_STATUS_COOK_RESULT.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      parm_id
///                 Parameter id of the parameter being updated.
///
/// @param[in]      index
///                 Index within the parameter's values tuple.
///

HAPI_DECL HAPI_RemoveParmExpression( const HAPI_Session * session,
                                   HAPI_NodeId node_id,
                                   HAPI_ParmId parm_id, int index );

/// @brief  Get single parm int value by name.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      parm_name
///                 The parm name.
///
/// @param[in]      index
///                 Index within the parameter's values tuple.
///
/// @param[out]     value
///                 The returned int value.
///


HAPI_DECL HAPI_GetParmIntValue( const HAPI_Session * session,
                                HAPI_NodeId node_id,
                                const char * parm_name,
                                int index,
                                int * value );

/// @brief  Fill an array of parameter int values. This is more efficient
///         than calling ::HAPI_GetParmIntValue() individually for each
///         parameter value.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[out]     values_array
///                 Array of ints at least the size of length.
///
/// @param[in]      start
///                 First index of range. Must be at least 0 and at
///                 most ::HAPI_NodeInfo::parmIntValueCount - 1.
///
/// @param[in]      length
///                 Must be at least 0 and at most
///                 ::HAPI_NodeInfo::parmIntValueCount - start.
///
HAPI_DECL HAPI_GetParmIntValues( const HAPI_Session * session,
                                 HAPI_NodeId node_id,
                                 int * values_array,
                                 int start, int length );

/// @brief  Get single parm float value by name.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      parm_name
///                 The parm name.
///
/// @param[in]      index
///                 Index within the parameter's values tuple.
///
/// @param[out]     value
///                 The returned float value.
///
HAPI_DECL HAPI_GetParmFloatValue( const HAPI_Session * session,
                                  HAPI_NodeId node_id,
                                  const char * parm_name,
                                  int index,
                                  float * value );

/// @brief  Fill an array of parameter float values. This is more efficient
///         than calling ::HAPI_GetParmFloatValue() individually for each
///         parameter value.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[out]     values_array
///                 Array of floats at least the size of length.
///
/// @param[in]      start
///                 First index of range. Must be at least 0 and at
///                 most ::HAPI_NodeInfo::parmFloatValueCount - 1.
///
/// @param[in]      length
///                 Must be at least 1 and at most
///                 ::HAPI_NodeInfo::parmFloatValueCount - start.
///
HAPI_DECL HAPI_GetParmFloatValues( const HAPI_Session * session,
                                   HAPI_NodeId node_id,
                                   float * values_array,
                                   int start, int length );

/// @brief  Get single parm string value by name.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      parm_name
///                 The name of the parameter.
///
/// @param[in]      index
///                 Index within the parameter's values tuple.
///
/// @param[in]      evaluate
///                 Whether or not to evaluate the string expression.
///                 For example, the string "$F" would evaluate to the
///                 current frame number. So, passing in evaluate = false
///                 would give you back the string "$F" and passing
///                 in evaluate = true would give you back "1" (assuming
///                 the current frame is 1).
///
/// @param[out]     value
///                 The returned string value.
///
HAPI_DECL HAPI_GetParmStringValue( const HAPI_Session * session,
                                   HAPI_NodeId node_id,
                                   const char * parm_name,
                                   int index,
                                   HAPI_Bool evaluate,
                                   HAPI_StringHandle * value );

/// @brief  Fill an array of parameter string handles. These handles must
///         be used in conjunction with ::HAPI_GetString() to get the
///         actual string values. This is more efficient than calling
///         ::HAPI_GetParmStringValue() individually for each
///         parameter value.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      evaluate
///                 Whether or not to evaluate the string expression.
///                 For example, the string "$F" would evaluate to the
///                 current frame number. So, passing in evaluate = false
///                 would give you back the string "$F" and passing
///                 in evaluate = true would give you back "1" (assuming
///                 the current frame is 1).
///
/// @param[out]     values_array
///                 Array of integers at least the size of length.
///
/// @param[in]      start
///                 First index of range. Must be at least 0 and at
///                 most ::HAPI_NodeInfo::parmStringValueCount - 1.
///
/// @param[in]      length
///                 Must be at least 1 and at most
///                 ::HAPI_NodeInfo::parmStringValueCount - start.
///
HAPI_DECL HAPI_GetParmStringValues( const HAPI_Session * session,
                                    HAPI_NodeId node_id,
                                    HAPI_Bool evaluate,
                                    HAPI_StringHandle * values_array,
                                    int start, int length );

/// @brief  Get a single node id parm value of an Op Path parameter. This is
///         how you see which node is connected as an input for the current
///         node (via parameter).
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      parm_name
///                 The name of the parameter.
///
/// @param[out]     value
///                 The node id of the node being pointed to by the parm.
///                 If there is no node found, -1 will be returned.
///
HAPI_DECL HAPI_GetParmNodeValue( const HAPI_Session * session,
                                 HAPI_NodeId node_id,
                                 const char * parm_name,
                                 HAPI_NodeId * value );

/// @brief  Extract a file specified by path on a parameter. This will copy
///         the file to the destination directory from wherever it might be,
///         inlcuding inside the asset definition or online.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      parm_name
///                 The name of the parameter.
///
/// @param[in]      destination_directory
///                 The destination directory to copy the file to.
///
/// @param[in]      destination_file_name
///                 The destination file name.
///
HAPI_DECL HAPI_GetParmFile( const HAPI_Session * session,
                            HAPI_NodeId node_id,
                            const char * parm_name,
                            const char * destination_directory,
                            const char * destination_file_name );

/// @brief  Fill an array of ::HAPI_ParmChoiceInfo structs with parameter
///         choice list information from the asset instance node.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[out]     parm_choices_array
///                 Array of ::HAPI_ParmChoiceInfo exactly the size of
///                 length.
///
/// @param[in]      start
///                 First index of range. Must be at least 0 and at
///                 most ::HAPI_NodeInfo::parmChoiceCount - 1.
///
/// @param[in]      length
///                 Must be at least 1 and at most
///                 ::HAPI_NodeInfo::parmChoiceCount - start.
///
HAPI_DECL HAPI_GetParmChoiceLists( const HAPI_Session * session,
                                   HAPI_NodeId node_id,
                                   HAPI_ParmChoiceInfo *parm_choices_array,
                                   int start, int length );

/// @brief  Set single parm int value by name.
///
///         @note Regardless of the value, when calling this function
///         on a parameter, if that parameter has a callback function
///         attached to it, that callback function will be called. For
///         example, if the parameter is a button the button will be
///         pressed.
///
///         @note In threaded mode, this is an _async call_!
///
///         This API will invoke the cooking thread if threading is
///         enabled. This means it will return immediately. Use
///         the status and cooking count APIs under DIAGNOSTICS to get
///         a sense of the progress. All other API calls will block
///         until the cook operation has finished.
///
///         Also note that the cook result won't be of type
///         ::HAPI_STATUS_CALL_RESULT like all calls (including this one).
///         Whenever the threading cook is done it will fill the
///         @a cook result which is queried using
///         ::HAPI_STATUS_COOK_RESULT.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      parm_name
///                 The parm name.
///
/// @param[in]      index
///                 Index within the parameter's values tuple.
///
/// @param[in]      value
///                 The int value.
///
HAPI_DECL HAPI_SetParmIntValue( const HAPI_Session * session,
                                HAPI_NodeId node_id,
                                const char * parm_name,
                                int index,
                                int value );

/// @brief  Set (push) an array of parameter int values.
///
///         @note Regardless of the values, when calling this function
///         on a set of parameters, if any parameter has a callback
///         function attached to it, that callback function will be called.
///         For example, if the parameter is a button the button will be
///         pressed.
///
///         @note In threaded mode, this is an _async call_!
///
///         This API will invoke the cooking thread if threading is
///         enabled. This means it will return immediately. Use
///         the status and cooking count APIs under DIAGNOSTICS to get
///         a sense of the progress. All other API calls will block
///         until the cook operation has finished.
///
///         Also note that the cook result won't be of type
///         ::HAPI_STATUS_CALL_RESULT like all calls (including this one).
///         Whenever the threading cook is done it will fill the
///         @a cook result which is queried using
///         ::HAPI_STATUS_COOK_RESULT.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      values_array
///                 Array of integers at least the size of length.
///
/// @param[in]      start
///                 First index of range. Must be at least 0 and at
///                 most ::HAPI_NodeInfo::parmIntValueCount - 1.
///
/// @param[in]      length
///                 Must be at least 1 and at most
///                 ::HAPI_NodeInfo::parmIntValueCount - start.
///
HAPI_DECL HAPI_SetParmIntValues( const HAPI_Session * session,
                                 HAPI_NodeId node_id,
                                 const int * values_array,
                                 int start, int length );

/// @brief  Set single parm float value by name.
///
///         @note Regardless of the value, when calling this function
///         on a parameter, if that parameter has a callback function
///         attached to it, that callback function will be called. For
///         example, if the parameter is a button the button will be
///         pressed.
///
///         @note In threaded mode, this is an _async call_!
///
///         This API will invoke the cooking thread if threading is
///         enabled. This means it will return immediately. Use
///         the status and cooking count APIs under DIAGNOSTICS to get
///         a sense of the progress. All other API calls will block
///         until the cook operation has finished.
///
///         Also note that the cook result won't be of type
///         ::HAPI_STATUS_CALL_RESULT like all calls (including this one).
///         Whenever the threading cook is done it will fill the
///         @a cook result which is queried using
///         ::HAPI_STATUS_COOK_RESULT.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      parm_name
///                 The parm name.
///
/// @param[in]      index
///                 Index within the parameter's values tuple.
///
/// @param[in]      value
///                 The float value.
///
HAPI_DECL HAPI_SetParmFloatValue( const HAPI_Session * session,
                                  HAPI_NodeId node_id,
                                  const char * parm_name,
                                  int index,
                                  float value );

/// @brief  Set (push) an array of parameter float values.
///
///         @note Regardless of the values, when calling this function
///         on a set of parameters, if any parameter has a callback
///         function attached to it, that callback function will be called.
///         For example, if the parameter is a button the button will be
///         pressed.
///
///         @note In threaded mode, this is an _async call_!
///
///         This API will invoke the cooking thread if threading is
///         enabled. This means it will return immediately. Use
///         the status and cooking count APIs under DIAGNOSTICS to get
///         a sense of the progress. All other API calls will block
///         until the cook operation has finished.
///
///         Also note that the cook result won't be of type
///         ::HAPI_STATUS_CALL_RESULT like all calls (including this one).
///         Whenever the threading cook is done it will fill the
///         @a cook result which is queried using
///         ::HAPI_STATUS_COOK_RESULT.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      values_array
///                 Array of floats at least the size of length.
///
/// @param[in]      start
///                 First index of range. Must be at least 0 and at
///                 most ::HAPI_NodeInfo::parmFloatValueCount - 1.
///
/// @param[in]      length
///                 Must be at least 1 and at most
///                 ::HAPI_NodeInfo::parmFloatValueCount - start.
///
HAPI_DECL HAPI_SetParmFloatValues( const HAPI_Session * session,
                                   HAPI_NodeId node_id,
                                   const float * values_array,
                                   int start, int length );

/// @brief  Set (push) a string value. We can only set a single value at
///         a time because we want to avoid fixed size string buffers.
///
///         @note Regardless of the value, when calling this function
///         on a parameter, if that parameter has a callback function
///         attached to it, that callback function will be called. For
///         example, if the parameter is a button the button will be
///         pressed.
///
///         @note In threaded mode, this is an _async call_!
///
///         This API will invoke the cooking thread if threading is
///         enabled. This means it will return immediately. Use
///         the status and cooking count APIs under DIAGNOSTICS to get
///         a sense of the progress. All other API calls will block
///         until the cook operation has finished.
///
///         Also note that the cook result won't be of type
///         ::HAPI_STATUS_CALL_RESULT like all calls (including this one).
///         Whenever the threading cook is done it will fill the
///         @a cook result which is queried using
///         ::HAPI_STATUS_COOK_RESULT.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      value
///                 The string value.
///
/// @param[in]      parm_id
///                 Parameter id of the parameter being updated.
///
/// @param[in]      index
///                 Index within the parameter's values tuple.
///
HAPI_DECL HAPI_SetParmStringValue( const HAPI_Session * session,
                                   HAPI_NodeId node_id,
                                   const char * value,
                                   HAPI_ParmId parm_id, int index );

/// @brief  Set a node id parm value of an Op Path parameter. For example,
///         This is how you connect the geometry output of an asset to the
///         geometry input of another asset - whether the input is a parameter
///         or a node input (the top of the node). Node inputs get converted
///         top parameters in HAPI.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      parm_name
///                 The name of the parameter.
///
/// @param[in]      value
///                 The node id of the node being connected. Pass -1 to
///                 disconnect.
///
HAPI_DECL HAPI_SetParmNodeValue( const HAPI_Session * session,
                                 HAPI_NodeId node_id,
                                 const char * parm_name,
                                 HAPI_NodeId value );

/// @brief Insert an instance of a multiparm before instance_position.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      parm_id
///                 A parm id given by a ::HAPI_ParmInfo struct that
///                 has type ::HAPI_PARMTYPE_MULTIPARMLIST.
///
/// @param[in]      instance_position
///                 The new instance will be inserted at this position
///                 index. Do note the multiparms can start at position
///                 1 or 0. Use ::HAPI_ParmInfo::instanceStartOffset to
///                 distinguish.
///
HAPI_DECL HAPI_InsertMultiparmInstance( const HAPI_Session * session,
                                        HAPI_NodeId node_id,
                                        HAPI_ParmId parm_id,
                                        int instance_position );

/// @brief Remove the instance of a multiparm given by instance_position.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      parm_id
///                 A parm id given by a ::HAPI_ParmInfo struct that
///                 has type ::HAPI_PARMTYPE_MULTIPARMLIST.
///
/// @param[in]      instance_position
///                 The instance at instance_position will removed.
///
HAPI_DECL HAPI_RemoveMultiparmInstance( const HAPI_Session * session,
                                        HAPI_NodeId node_id,
                                        HAPI_ParmId parm_id,
                                        int instance_position );

// HANDLES ------------------------------------------------------------------

/// @brief  Fill an array of ::HAPI_HandleInfo structs with information
///         about every exposed user manipulation handle on the node.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[out]     handle_infos_array
///                 Array of ::HAPI_HandleInfo at least the size of length.
///
/// @param[in]      start
///                 First index of range. Must be at least 0 and at
///                 most ::HAPI_AssetInfo::handleCount - 1.
///
/// @param[in]      length
///                 Must be at least 1 and at most
///                 ::HAPI_AssetInfo::handleCount - start.
///
HAPI_DECL HAPI_GetHandleInfo( const HAPI_Session * session,
                              HAPI_NodeId node_id,
                              HAPI_HandleInfo * handle_infos_array,
                              int start, int length );

/// @brief  Fill an array of ::HAPI_HandleInfo structs with information
///         about every exposed user manipulation handle on the node.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      handle_index
///                 The index of the handle, from 0 to handleCount - 1
///                 from the call to ::HAPI_GetAssetInfo().
///
/// @param[out]     handle_binding_infos_array
///                 Array of ::HAPI_HandleBindingInfo at least the size
///                 of length.
///
/// @param[in]      start
///                 First index of range. Must be at least 0 and at
///                 most ::HAPI_HandleInfo::bindingsCount - 1.
///
/// @param[in]      length
///                 Must be at least 0 and at most
///                 ::HAPI_HandleInfo::bindingsCount - start.
///
HAPI_DECL HAPI_GetHandleBindingInfo(
                        const HAPI_Session * session,
                        HAPI_NodeId node_id,
                        int handle_index,
                        HAPI_HandleBindingInfo * handle_binding_infos_array,
                        int start, int length );

// PRESETS ------------------------------------------------------------------

/// @brief  Generate a preset blob of the current state of all the
///         parameter values, cache it, and return its size in bytes.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The exposed node id.
///
/// @param[in]      preset_type
///                 The preset type.
///
/// @param[in]      preset_name
///                 Optional. This is only used if the @p preset_type is
///                 ::HAPI_PRESETTYPE_IDX. If NULL is given, the preset
///                 name will be the same as the name of the node with
///                 the given @p node_id.
///
/// @param[out]     buffer_length
///                 Size of the buffer.
///
HAPI_DECL HAPI_GetPresetBufLength( const HAPI_Session * session,
                                   HAPI_NodeId node_id,
                                   HAPI_PresetType preset_type,
                                   const char * preset_name,
                                   int * buffer_length );

/// @brief  Generates a preset for the given asset.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The exposed node id.
///
/// @param[out]     buffer
///                 Buffer to hold the preset data.
///
/// @param[in]      buffer_length
///                 Size of the buffer. Should be the same as the length
///                 returned by ::HAPI_GetPresetBufLength().
///
HAPI_DECL HAPI_GetPreset( const HAPI_Session * session,
                          HAPI_NodeId node_id,
                          char * buffer,
                          int buffer_length );

/// @brief  Sets a particular asset to a given preset.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The exposed node id.
///
/// @param[in]      preset_type
///                 The preset type.
///
/// @param[in]      preset_name
///                 Optional. This is only used if the @p preset_type is
///                 ::HAPI_PRESETTYPE_IDX. If NULL is give, the first
///                 preset in the IDX file will be chosen.
///
/// @param[in]      buffer
///                 Buffer to hold the preset data.
///
/// @param[in]      buffer_length
///                 Size of the buffer.
///
HAPI_DECL HAPI_SetPreset( const HAPI_Session * session,
                          HAPI_NodeId node_id,
                          HAPI_PresetType preset_type,
                          const char * preset_name,
                          const char * buffer,
                          int buffer_length );

// OBJECTS ------------------------------------------------------------------

/// @brief  Get the object info on an OBJ node.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[out]     object_info
///                 The output ::HAPI_ObjectInfo.
///
HAPI_DECL HAPI_GetObjectInfo( const HAPI_Session * session,
                              HAPI_NodeId node_id,
                              HAPI_ObjectInfo * object_info );

/// @brief  Get the tranform of an OBJ node.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The object node id.
///
/// @param[in]      relative_to_node_id
///                 The object node id for the object to which the returned
///                 transform will be relative to. Pass -1 or the node_id
///                 to just get the object's local transform.
///
/// @param[in]      rst_order
///                 The order of application of translation, rotation and
///                 scale.
///
/// @param[out]     transform
///                 The output ::HAPI_Transform transform.
///
HAPI_DECL HAPI_GetObjectTransform( const HAPI_Session * session,
                                   HAPI_NodeId node_id,
                                   HAPI_NodeId relative_to_node_id,
                                   HAPI_RSTOrder rst_order,
                                   HAPI_Transform * transform );

/// @brief  Compose a list of child object nodes given a parent node id.
///
///         Use the @c object_count returned by this function to get the
///         ::HAPI_ObjectInfo structs for each child object using
///         ::HAPI_GetComposedObjectList().
///
///         Note, if not using the @c categories arg, this is equivalent to:
///         @code
///         HAPI_ComposeChildNodeList(
///             session, parent_node_id,
///             HAPI_NODETYPE_OBJ,
///             HAPI_NODEFLAGS_OBJ_GEOMETRY,
///             true, &object_count );
///         @endcode
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      parent_node_id
///                 The parent node id.
///
/// @param[in]      categories
///                 (Optional) Lets you filter object nodes by their render
///                 categories. This is a standard OBJ parameter, usually
///                 under the Render > Shading tab. If an OBJ node does not
///                 have this parameter, one can always add it as a spare.
///
///                 The value of this string argument should be NULL if not
///                 used or a space-separated list of category names.
///                 Multiple category names will be treated as an AND op.
///
/// @param[out]     object_count
///                 The number of object nodes currently under the parent.
///                 Use this count with a call to
///                 ::HAPI_GetComposedObjectList() to get the object infos.
///
HAPI_DECL HAPI_ComposeObjectList( const HAPI_Session * session,
                                  HAPI_NodeId parent_node_id,
                                  const char * categories,
                                  int * object_count );

/// @brief  Fill an array of ::HAPI_ObjectInfo structs.
///
///         This is best used with ::HAPI_ComposeObjectList() with.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      parent_node_id
///                 The parent node id.
///
/// @param[out]     object_infos_array
///                 Array of ::HAPI_ObjectInfo at least the size of
///                 @c length.
///
/// @param[in]      start
///                 At least @c 0 and at most @c object_count returned by
///                 ::HAPI_ComposeObjectList().
///
/// @param[in]      length
///                 Given @c object_count returned by
///                 ::HAPI_ComposeObjectList(), @c length should be at least
///                 @c 0 and at most <tt>object_count - start</tt>.
///
HAPI_DECL HAPI_GetComposedObjectList( const HAPI_Session * session,
                                      HAPI_NodeId parent_node_id,
                                      HAPI_ObjectInfo * object_infos_array,
                                      int start, int length );

/// @brief  Fill an array of ::HAPI_Transform structs.
///
///         This is best used with ::HAPI_ComposeObjectList() with.
///
///         Note that these transforms will be relative to the
///         @c parent_node_id originally given to ::HAPI_ComposeObjectList()
///         and expected to be the same with this call. If @c parent_node_id
///         is not an OBJ node, the transforms will be given as they are on
///         the object node itself.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      parent_node_id
///                 The parent node id. The object transforms will be
///                 relative to this node unless this node is not an OBJ.
///
/// @param[in]      rst_order
///                 The order of application of translation, rotation and
///                 scale.
///
/// @param[out]     transform_array
///                 Array of ::HAPI_Transform at least the size of
///                 length.
///
/// @param[in]      start
///                 At least @c 0 and at most @c object_count returned by
///                 ::HAPI_ComposeObjectList().
///
/// @param[in]      length
///                 Given @c object_count returned by
///                 ::HAPI_ComposeObjectList(), @c length should be at least
///                 @c 0 and at most <tt>object_count - start</tt>.
///
HAPI_DECL HAPI_GetComposedObjectTransforms( const HAPI_Session * session,
                                            HAPI_NodeId parent_node_id,
                                            HAPI_RSTOrder rst_order,
                                            HAPI_Transform * transform_array,
                                            int start, int length );

/// @brief  Get the node ids for the objects being instanced by an
///         Instance OBJ node.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      object_node_id
///                 The object node id.
///
/// @param[out]     instanced_node_id_array
///                 Array of ::HAPI_NodeId at least the size of length.
///
/// @param[in]      start
///                 First index of range. Must be at least 0 and at
///                 most ::HAPI_PartInfo::pointCount - 1. This is the 0th
///                 part of the display geo of the instancer object node.
///
/// @param[in]      length
///                 Must be at least 0 and at most
///                 ::HAPI_PartInfo::pointCount - @p start. This is the 0th
///                 part of the display geo of the instancer object node.
///
HAPI_DECL HAPI_GetInstancedObjectIds( const HAPI_Session * session,
                                      HAPI_NodeId object_node_id,
                                      HAPI_NodeId * instanced_node_id_array,
                                      int start, int length );

/// @brief  Fill an array of ::HAPI_Transform structs with the transforms
///         of each instance of this instancer object.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      object_node_id
///                 The object node id.
///
/// @param[in]      rst_order
///                 The order of application of translation, rotation and
///                 scale.
///
/// @param[out]     transforms_array
///                 Array of ::HAPI_Transform at least the size of length.
///
/// @param[in]      start
///                 First index of range. Must be at least 0 and at
///                 most ::HAPI_PartInfo::pointCount - 1. This is the 0th
///                 part of the display geo of the instancer object node.
///
/// @param[in]      length
///                 Must be at least 0 and at most
///                 ::HAPI_PartInfo::pointCount - @p start. This is the 0th
///                 part of the display geo of the instancer object node.
///
HAPI_DECL HAPI_GetInstanceTransforms( const HAPI_Session * session,
                                      HAPI_NodeId object_node_id,
                                      HAPI_RSTOrder rst_order,
                                      HAPI_Transform * transforms_array,
                                      int start, int length );

/// @brief  Fill an array of ::HAPI_Transform structs with the transforms
///         of each instance of this instancer object for a given part.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The object node id.
///
/// @param[in]      part_id
///                 The part id.
///
/// @param[in]      rst_order
///                 The order of application of translation, rotation and
///                 scale.
///
/// @param[out]     transforms_array
///                 Array of ::HAPI_Transform at least the size of length.
///
/// @param[in]      start
///                 First index of range. Must be at least 0 and at
///                 most ::HAPI_PartInfo::pointCount - 1. This is the 0th
///                 part of the display geo of the instancer object node.
///
/// @param[in]      length
///                 Must be at least 0 and at most
///                 ::HAPI_PartInfo::pointCount - @p start. This is the 0th
///                 part of the display geo of the instancer object node.
///
HAPI_DECL HAPI_GetInstanceTransformsOnPart( const HAPI_Session *session,
                                            HAPI_NodeId node_id,
                                            HAPI_PartId part_id,
                                            HAPI_RSTOrder rst_order,
                                            HAPI_Transform *transforms_array,
                                            int start, int length );

/// @brief  Set the transform of an individual object. Note that the object
///         nodes have to either be editable or have their transform
///         parameters exposed at the asset level. This won't work otherwise.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The object node id.
///
/// @param[in]      trans
///                 A ::HAPI_TransformEuler that stores the transform.
///
HAPI_DECL HAPI_SetObjectTransform( const HAPI_Session * session,
                                   HAPI_NodeId node_id,
                                   const HAPI_TransformEuler * trans );

// GEOMETRY GETTERS ---------------------------------------------------------

/// @brief  Get the display geo (SOP) node inside an Object node. If there
///         there are multiple display SOP nodes, only the first one is
///         returned. If the node is a display SOP itself, even if a network,
///         it will return its own geo info. If the node is a SOP but not
///         a network and not the display SOP, this function will fail.
///
///         The above implies that you can safely call this function on both
///         OBJ and SOP asset nodes and get the same (equivalent) geometry
///         display node back. SOP asset nodes will simply return themselves.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      object_node_id
///                 The object node id.
///
/// @param[out]     geo_info
///                 ::HAPI_GeoInfo return value.
///
HAPI_DECL HAPI_GetDisplayGeoInfo( const HAPI_Session * session,
                                  HAPI_NodeId object_node_id,
                                  HAPI_GeoInfo * geo_info );

/// @brief  Get the geometry info struct (::HAPI_GeoInfo) on a SOP node.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[out]     geo_info
///                 ::HAPI_GeoInfo return value.
///
HAPI_DECL HAPI_GetGeoInfo( const HAPI_Session * session,
                           HAPI_NodeId node_id,
                           HAPI_GeoInfo * geo_info );

/// @brief  Get a particular part info struct.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The SOP node id.
///
/// @param[in]      part_id
///                 The part id.
///
/// @param[out]     part_info
///                 ::HAPI_PartInfo return value.
///
HAPI_DECL HAPI_GetPartInfo( const HAPI_Session * session,
                            HAPI_NodeId node_id,
                            HAPI_PartId part_id,
                            HAPI_PartInfo * part_info );

/// @brief  Get the array of faces where the nth integer in the array is
///         the number of vertices the nth face has.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      part_id
///                 The part id.
///
/// @param[out]     face_counts_array
///                 An integer array at least the size of length.
///
/// @param[in]      start
///                 First index of range. Must be at least 0 and at
///                 most ::HAPI_PartInfo::faceCount - 1.
///
/// @param[in]      length
///                 Must be at least 0 and at most
///                 ::HAPI_PartInfo::faceCount - @p start.
///
HAPI_DECL HAPI_GetFaceCounts( const HAPI_Session * session,
                              HAPI_NodeId node_id,
                              HAPI_PartId part_id,
                              int * face_counts_array,
                              int start, int length );

/// @brief  Get array containing the vertex-point associations where the
///         ith element in the array is the point index the ith vertex
///         associates with.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      part_id
///                 The part id.
///
/// @param[out]     vertex_list_array
///                 An integer array at least the size of length.
///
/// @param[in]      start
///                 First index of range. Must be at least 0 and at
///                 most ::HAPI_PartInfo::vertexCount - 1.
///
/// @param[in]      length
///                 Must be at least 0 and at most
///                 ::HAPI_PartInfo::vertexCount - @p start.
///
HAPI_DECL HAPI_GetVertexList( const HAPI_Session * session,
                              HAPI_NodeId node_id,
                              HAPI_PartId part_id,
                              int * vertex_list_array,
                              int start, int length );

/// @brief  Get the attribute info struct for the attribute specified by name.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      part_id
///                 The part id.
///
/// @param[in]      name
///                 Attribute name.
///
/// @param[in]      owner
///                 Attribute owner.
///
/// @param[out]     attr_info
///                 ::HAPI_AttributeInfo to be filled. Check
///                 ::HAPI_AttributeInfo::exists to see if this attribute
///                 exists.
///
HAPI_DECL HAPI_GetAttributeInfo( const HAPI_Session * session,
                                 HAPI_NodeId node_id,
                                 HAPI_PartId part_id,
                                 const char * name,
                                 HAPI_AttributeOwner owner,
                                 HAPI_AttributeInfo * attr_info );

/// @brief  Get list of attribute names by attribute owner. Note that the
///         name string handles are only valid until the next time this
///         function is called.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      part_id
///                 The part id.
///
/// @param[in]      owner
///                 The ::HAPI_AttributeOwner enum value specifying the
///                 owner of the attribute.
///
/// @param[out]     attribute_names_array
///                 Array of ints (string handles) to house the
///                 attribute names. Should be exactly the size of the
///                 appropriate attribute owner type count
///                 in ::HAPI_PartInfo.
///
/// @param[in]      count
///                 Sanity check count. Must be equal to the appropriate
///                 attribute owner type count in ::HAPI_PartInfo.
///
HAPI_DECL HAPI_GetAttributeNames( const HAPI_Session * session,
                                  HAPI_NodeId node_id,
                                  HAPI_PartId part_id,
                                  HAPI_AttributeOwner owner,
                                  HAPI_StringHandle * attribute_names_array,
                                  int count );

/// @brief  Get attribute integer data.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      part_id
///                 The part id.
///
/// @param[in]      name
///                 Attribute name.
///
/// @param[in]      attr_info
///                 ::HAPI_AttributeInfo used as input for what tuple size.
///                 you want. Also contains some sanity checks like
///                 data type. Generally should be the same struct
///                 returned by ::HAPI_GetAttributeInfo().
///
/// @param[in]      stride
///                 Specifies how many items to skip over for each element.
///                 With a stride of -1, the stride will be set to
///                 @c attr_info->tuple_size. Otherwise, the stride will be
///                 set to the maximum of @c attr_info->tuple_size and
///                 @c stride.
///
/// @param[out]     data_array
///                 An integer array at least the size of
///                 <tt>length * ::HAPI_AttributeInfo::tupleSize</tt>.
///
/// @param[in]      start
///                 First index of range. Must be at least 0 and at
///                 most ::HAPI_AttributeInfo::count - 1.
///
/// @param[in]      length
///                 Must be at least 0 and at most
///                 ::HAPI_AttributeInfo::count - @p start.
///                 Note, if 0 is passed for length, the function will just
///                 do nothing and return ::HAPI_RESULT_SUCCESS.
///
HAPI_DECL HAPI_GetAttributeIntData( const HAPI_Session * session,
                                    HAPI_NodeId node_id,
                                    HAPI_PartId part_id,
                                    const char * name,
                                    HAPI_AttributeInfo * attr_info,
                                    int stride,
                                    int * data_array,
                                    int start, int length );

/// @brief  Get attribute 64-bit integer data.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      part_id
///                 The part id.
///
/// @param[in]      name
///                 Attribute name.
///
/// @param[in]      attr_info
///                 ::HAPI_AttributeInfo used as input for what tuple size.
///                 you want. Also contains some sanity checks like
///                 data type. Generally should be the same struct
///                 returned by ::HAPI_GetAttributeInfo().
///
/// @param[in]      stride
///                 Specifies how many items to skip over for each element.
///                 With a stride of -1, the stride will be set to
///                 @c attr_info->tuple_size. Otherwise, the stride will be
///                 set to the maximum of @c attr_info->tuple_size and
///                 @c stride.
///
/// @param[out]     data_array
///                 An 64-bit integer array at least the size of
///                 <tt>length * ::HAPI_AttributeInfo::tupleSize</tt>.
///
/// @param[in]      start
///                 First index of range. Must be at least 0 and at
///                 most ::HAPI_AttributeInfo::count - 1.
///
/// @param[in]      length
///                 Must be at least 0 and at most
///                 ::HAPI_AttributeInfo::count - @p start.
///                 Note, if 0 is passed for length, the function will just
///                 do nothing and return ::HAPI_RESULT_SUCCESS.
///
HAPI_DECL HAPI_GetAttributeInt64Data( const HAPI_Session * session,
                                      HAPI_NodeId node_id,
                                      HAPI_PartId part_id,
                                      const char * name,
                                      HAPI_AttributeInfo * attr_info,
                                      int stride,
                                      HAPI_Int64 * data_array,
                                      int start, int length );

/// @brief  Get attribute float data.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      part_id
///                 The part id.
///
/// @param[in]      name
///                 Attribute name.
///
/// @param[in]      attr_info
///                 ::HAPI_AttributeInfo used as input for what tuple size.
///                 you want. Also contains some sanity checks like
///                 data type. Generally should be the same struct
///                 returned by ::HAPI_GetAttributeInfo().
///
/// @param[in]      stride
///                 Specifies how many items to skip over for each element.
///                 With a stride of -1, the stride will be set to
///                 @c attr_info->tuple_size. Otherwise, the stride will be
///                 set to the maximum of @c attr_info->tuple_size and
///                 @c stride.
///
/// @param[out]     data_array
///                 An float array at least the size of
///                 <tt>length * ::HAPI_AttributeInfo::tupleSize</tt>.
///
/// @param[in]      start
///                 First index of range. Must be at least 0 and at
///                 most ::HAPI_AttributeInfo::count - 1.
///
/// @param[in]      length
///                 Must be at least 0 and at most
///                 ::HAPI_AttributeInfo::count - @p start.
///                 Note, if 0 is passed for length, the function will just
///                 do nothing and return ::HAPI_RESULT_SUCCESS.
///
HAPI_DECL HAPI_GetAttributeFloatData( const HAPI_Session * session,
                                      HAPI_NodeId node_id,
                                      HAPI_PartId part_id,
                                      const char * name,
                                      HAPI_AttributeInfo * attr_info,
                                      int stride,
                                      float * data_array,
                                      int start, int length );

/// @brief  Get 64-bit attribute float data.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      part_id
///                 The part id.
///
/// @param[in]      name
///                 Attribute name.
///
/// @param[in]      attr_info
///                 ::HAPI_AttributeInfo used as input for what tuple size.
///                 you want. Also contains some sanity checks like
///                 data type. Generally should be the same struct
///                 returned by ::HAPI_GetAttributeInfo().
///
/// @param[in]      stride
///                 Specifies how many items to skip over for each element.
///                 With a stride of -1, the stride will be set to
///                 @c attr_info->tuple_size. Otherwise, the stride will be
///                 set to the maximum of @c attr_info->tuple_size and
///                 @c stride.
///
/// @param[out]     data_array
///                 An 64-bit float array at least the size of
///                 <tt>length * ::HAPI_AttributeInfo::tupleSize</tt>.
///
/// @param[in]      start
///                 First index of range. Must be at least 0 and at
///                 most ::HAPI_AttributeInfo::count - 1.
///
/// @param[in]      length
///                 Must be at least 0 and at most
///                 ::HAPI_AttributeInfo::count - @p start.
///                 Note, if 0 is passed for length, the function will just
///                 do nothing and return ::HAPI_RESULT_SUCCESS.
///
HAPI_DECL HAPI_GetAttributeFloat64Data( const HAPI_Session * session,
                                        HAPI_NodeId node_id,
                                        HAPI_PartId part_id,
                                        const char * name,
                                        HAPI_AttributeInfo * attr_info,
                                        int stride,
                                        double * data_array,
                                        int start, int length );

/// @brief  Get attribute string data. Note that the string handles
///         returned are only valid until the next time this function
///         is called.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      part_id
///                 The part id.
///
/// @param[in]      name
///                 Attribute name.
///
/// @param[in]      attr_info
///                 ::HAPI_AttributeInfo used as input for what tuple size.
///                 you want. Also contains some sanity checks like
///                 data type. Generally should be the same struct
///                 returned by ::HAPI_GetAttributeInfo().
///
/// @param[out]     data_array
///                 An ::HAPI_StringHandle array at least the size of
///                 <tt>length * ::HAPI_AttributeInfo::tupleSize</tt>.
///
/// @param[in]      start
///                 First index of range. Must be at least 0 and at
///                 most ::HAPI_AttributeInfo::count - 1.
///
/// @param[in]      length
///                 Must be at least 0 and at most
///                 ::HAPI_AttributeInfo::count - @p start.
///                 Note, if 0 is passed for length, the function will just
///                 do nothing and return ::HAPI_RESULT_SUCCESS.
///
HAPI_DECL HAPI_GetAttributeStringData( const HAPI_Session * session,
                                       HAPI_NodeId node_id,
                                       HAPI_PartId part_id,
                                       const char * name,
                                       HAPI_AttributeInfo * attr_info,
                                       HAPI_StringHandle * data_array,
                                       int start, int length );

/// @brief  Get group names for an entire geo. Please note that this
///         function is NOT per-part, but it is per-geo. The companion
///         function ::HAPI_GetGroupMembership() IS per-part. Also keep
///         in mind that the name string handles are only
///         valid until the next time this function is called.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      group_type
///                 The group type.
///
/// @param[out]     group_names_array
///                 The array of names to be filled. Should be the size
///                 given by ::HAPI_GeoInfo_GetGroupCountByType() with
///                 @p group_type and the ::HAPI_GeoInfo of @p geo_id.
///                 @note These string handles are only valid until the
///                 next call to ::HAPI_GetGroupNames().
///
/// @param[in]      group_count
///                 Sanity check. Should be less than or equal to the size
///                 of @p group_names.
///
HAPI_DECL HAPI_GetGroupNames( const HAPI_Session * session,
                              HAPI_NodeId node_id,
                              HAPI_GroupType group_type,
                              HAPI_StringHandle * group_names_array,
                              int group_count );

/// @brief  Get group membership.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      part_id
///                 The part id.
///
/// @param[in]      group_type
///                 The group type.
///
/// @param[in]      group_name
///                 The group name.
///
/// @param[out]     membership_array_all_equal
///                 (optional) Quick way to determine if all items are in
///                 the given group or all items our not in the group.
///                 You can just pass NULL here if not interested.
///
/// @param[out]     membership_array
///                 Array of ints that represent the membership of this
///                 group. Should be the size given by
///                 ::HAPI_PartInfo_GetElementCountByGroupType() with
///                 @p group_type and the ::HAPI_PartInfo of @p part_id.
///
/// @param[in]      start
///                 Start offset into the membership array. Must be
///                 less than ::HAPI_PartInfo_GetElementCountByGroupType().
///
/// @param[in]      length
///                 Should be less than or equal to the size
///                 of @p membership.
///
HAPI_DECL HAPI_GetGroupMembership( const HAPI_Session * session,
                                   HAPI_NodeId node_id,
                                   HAPI_PartId part_id,
                                   HAPI_GroupType group_type,
                                   const char * group_name,
                                   HAPI_Bool * membership_array_all_equal,
                                   int * membership_array,
                                   int start, int length );

/// @brief  Get group counts for a specific packed instanced part.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      part_id
///                 The part id. (should be a packed primitive)
///
/// @param[out]     pointGroupCount
///                 Number of point groups on the packed instance part.
///                 Will be set to -1 if the part is not a valid packed part.
///
/// @param[out]     primitiveGroupCount
///                 Number of primitive groups on the instanced part.
///                 Will be set to -1 if the part is not a valid instancer
///
HAPI_DECL HAPI_GetGroupCountOnPackedInstancePart( const HAPI_Session * session,
                                                  HAPI_NodeId node_id,
                                                  HAPI_PartId part_id,
                                                  int * pointGroupCount,
                                                  int * primitiveGroupCount );

/// @brief  Get the group names for a packed instance part
///         This functions allows you to get the group name for a specific
///         packed primitive part.
///         Keep in mind that the name string handles are only
///         valid until the next time this function is called.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      part_id
///                 The part id. (should be a packed primitive)
///
/// @param[in]      group_type
///                 The group type.
///
/// @param[out]     group_names_array
///                 The array of names to be filled. Should be the size
///                 given by ::HAPI_GetGroupCountOnInstancedPart() with
///                 @p group_type and the ::HAPI_PartInfo of @p part_id.
///                 @note These string handles are only valid until the
///                 next call to ::HAPI_GetGroupNamesOnPackedInstancePart().
///
/// @param[in]      group_count
///                 Sanity check. Should be less than or equal to the size
///                 of @p group_names.
///
HAPI_DECL HAPI_GetGroupNamesOnPackedInstancePart( const HAPI_Session * session,
                                                  HAPI_NodeId node_id,
                                                  HAPI_PartId part_id,
                                                  HAPI_GroupType group_type,
                                                  HAPI_StringHandle * group_names_array,
                                                  int group_count );

/// @brief  Get group membership for a packed instance part
///         This functions allows you to get the group membership for a specific
///         packed primitive part.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      part_id
///                 The part id. (should be a packed primitive)
///
/// @param[in]      group_type
///                 The group type.
///
/// @param[in]      group_name
///                 The group name.
///
/// @param[out]     membership_array_all_equal
///                 (optional) Quick way to determine if all items are in
///                 the given group or all items our not in the group.
///                 You can just pass NULL here if not interested.
///
/// @param[out]     membership_array
///                 Array of ints that represent the membership of this
///                 group. Should be the size given by
///                 ::HAPI_PartInfo_GetElementCountByGroupType() with
///                 @p group_type and the ::HAPI_PartInfo of @p part_id.
///
/// @param[in]      start
///                 Start offset into the membership array. Must be
///                 less than ::HAPI_PartInfo_GetElementCountByGroupType().
///
/// @param[in]      length
///                 Should be less than or equal to the size
///                 of @p membership.
///
HAPI_DECL HAPI_GetGroupMembershipOnPackedInstancePart( const HAPI_Session * session,
                                                       HAPI_NodeId node_id,
                                                       HAPI_PartId part_id,
                                                       HAPI_GroupType group_type,
                                                       const char * group_name,
                                                       HAPI_Bool * membership_array_all_equal,
                                                       int * membership_array,
                                                       int start, int length );

/// @brief  Get the part ids that this instancer part is instancing.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      part_id
///                 The instancer part id.
///
/// @param[out]     instanced_parts_array
///                 Array of ::HAPI_PartId's to instance.
///
/// @param[in]      start
///                 Should be less than @p part_id's
///                 ::HAPI_PartInfo::instancedPartCount but more than or
///                 equal to 0.
///
/// @param[in]      length
///                 Should be less than @p part_id's
///                 ::HAPI_PartInfo::instancedPartCount - @p start.
///
HAPI_DECL HAPI_GetInstancedPartIds( const HAPI_Session * session,
                                    HAPI_NodeId node_id,
                                    HAPI_PartId part_id,
                                    HAPI_PartId * instanced_parts_array,
                                    int start, int length );

/// @brief  Get the instancer part's list of transforms on which to
///         instance the instanced parts you got from
///         ::HAPI_GetInstancedPartIds().
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      part_id
///                 The instancer part id.
///
/// @param[in]      rst_order
///                 The order of application of translation, rotation and
///                 scale.
///
/// @param[out]     transforms_array
///                 Array of ::HAPI_PartId's to instance.
///
/// @param[in]      start
///                 Should be less than @p part_id's
///                 ::HAPI_PartInfo::instanceCount but more than or
///                 equal to 0.
///
/// @param[in]      length
///                 Should be less than @p part_id's
///                 ::HAPI_PartInfo::instanceCount - @p start.
///
HAPI_DECL HAPI_GetInstancerPartTransforms( const HAPI_Session * session,
                                           HAPI_NodeId node_id,
                                           HAPI_PartId part_id,
                                           HAPI_RSTOrder rst_order,
                                           HAPI_Transform * transforms_array,
                                           int start, int length );

// GEOMETRY SETTERS ---------------------------------------------------------

/// @brief  Set the main part info struct (::HAPI_PartInfo).
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The SOP node id.
///
/// @param[in]      part_id
///                 Currently not used. Just pass 0.
///
/// @param[in]      part_info
///                 ::HAPI_PartInfo value that describes the input
///                 geometry.
///
HAPI_DECL HAPI_SetPartInfo( const HAPI_Session * session,
                            HAPI_NodeId node_id,
                            HAPI_PartId part_id,
                            const HAPI_PartInfo * part_info );

/// @brief  Set the array of faces where the nth integer in the array is
///         the number of vertices the nth face has.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The SOP node id.
///
/// @param[in]      part_id
///                 Currently not used. Just pass 0.
///
/// @param[in]      face_counts_array
///                 An integer array at least the size of @p length.
///
/// @param[in]      start
///                 First index of range. Must be at least 0 and at
///                 most ::HAPI_PartInfo::faceCount - 1.
///
/// @param[in]      length
///                 Must be at least 0 and at most
///                 ::HAPI_PartInfo::faceCount - @p start.
///
HAPI_DECL HAPI_SetFaceCounts( const HAPI_Session * session,
                              HAPI_NodeId node_id,
                              HAPI_PartId part_id,
                              const int * face_counts_array,
                              int start, int length );

/// @brief  Set array containing the vertex-point associations where the
///         ith element in the array is the point index the ith vertex
///         associates with.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The SOP node id.
///
/// @param[in]      part_id
///                 Currently not used. Just pass 0.
///
/// @param[in]      vertex_list_array
///                 An integer array at least the size of length.
///
/// @param[in]      start
///                 First index of range. Must be at least 0 and at
///                 most ::HAPI_PartInfo::vertexCount - 1.
///
/// @param[in]      length
///                 Must be at least 0 and at most
///                 ::HAPI_PartInfo::vertexCount - @p start.
///
HAPI_DECL HAPI_SetVertexList( const HAPI_Session * session,
                              HAPI_NodeId node_id,
                              HAPI_PartId part_id,
                              const int * vertex_list_array,
                              int start, int length );

/// @brief  Add an attribute.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The SOP node id.
///
/// @param[in]      part_id
///                 Currently not used. Just pass 0.
///
/// @param[in]      name
///                 Attribute name.
///
/// @param[in]      attr_info
///                 ::HAPI_AttributeInfo stores attribute properties.
///
HAPI_DECL HAPI_AddAttribute( const HAPI_Session * session,
                             HAPI_NodeId node_id,
                             HAPI_PartId part_id,
                             const char * name,
                             const HAPI_AttributeInfo * attr_info );
/// @brief  Delete an attribute from an input geo
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
 ///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The SOP node id.
///
/// @param[in]      part_id
///                 Currently not used. Just pass 0.
///
/// @param[in]      name
///                 Attribute name.
///
/// @param[in]      attr_info
///                 ::HAPI_AttributeInfo stores attribute properties.
///
HAPI_DECL HAPI_DeleteAttribute( const HAPI_Session * session,
                             HAPI_NodeId node_id,
                             HAPI_PartId part_id,
                             const char * name,
                             const HAPI_AttributeInfo * attr_info );

/// @brief  Set attribute integer data.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The SOP node id.
///
/// @param[in]      part_id
///                 Currently not used. Just pass 0.
///
/// @param[in]      name
///                 Attribute name.
///
/// @param[in]      attr_info
///                 ::HAPI_AttributeInfo used as input for what tuple size.
///                 you want. Also contains some sanity checks like
///                 data type. Generally should be the same struct
///                 returned by ::HAPI_GetAttributeInfo().
///
/// @param[out]     data_array
///                 An integer array at least the size of
///                 <tt>length * ::HAPI_AttributeInfo::tupleSize</tt>.
///
/// @param[in]      start
///                 First index of range. Must be at least 0 and at
///                 most ::HAPI_AttributeInfo::count - 1.
///
/// @param[in]      length
///                 Must be at least 0 and at most
///                 ::HAPI_AttributeInfo::count - @p start.
///
HAPI_DECL HAPI_SetAttributeIntData( const HAPI_Session * session,
                                    HAPI_NodeId node_id,
                                    HAPI_PartId part_id,
                                    const char * name,
                                    const HAPI_AttributeInfo * attr_info,
                                    const int * data_array,
                                    int start, int length );

/// @brief  Set 64-bit attribute integer data.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The SOP node id.
///
/// @param[in]      part_id
///                 Currently not used. Just pass 0.
///
/// @param[in]      name
///                 Attribute name.
///
/// @param[in]      attr_info
///                 ::HAPI_AttributeInfo used as input for what tuple size.
///                 you want. Also contains some sanity checks like
///                 data type. Generally should be the same struct
///                 returned by ::HAPI_GetAttributeInfo().
///
/// @param[out]     data_array
///                 An 64-bit integer array at least the size of
///                 <tt>length * ::HAPI_AttributeInfo::tupleSize</tt>.
///
/// @param[in]      start
///                 First index of range. Must be at least 0 and at
///                 most ::HAPI_AttributeInfo::count - 1.
///
/// @param[in]      length
///                 Must be at least 0 and at most
///                 ::HAPI_AttributeInfo::count - @p start.
///
HAPI_DECL HAPI_SetAttributeInt64Data( const HAPI_Session * session,
                                      HAPI_NodeId node_id,
                                      HAPI_PartId part_id,
                                      const char * name,
                                      const HAPI_AttributeInfo * attr_info,
                                      const HAPI_Int64 * data_array,
                                      int start, int length );

/// @brief  Set attribute float data.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The SOP node id.
///
/// @param[in]      part_id
///                 Currently not used. Just pass 0.
///
/// @param[in]      name
///                 Attribute name.
///
/// @param[in]      attr_info
///                 ::HAPI_AttributeInfo used as input for what tuple size.
///                 you want. Also contains some sanity checks like
///                 data type. Generally should be the same struct
///                 returned by ::HAPI_GetAttributeInfo().
///
/// @param[out]     data_array
///                 An float array at least the size of
///                 <tt>length * ::HAPI_AttributeInfo::tupleSize</tt>.
///
/// @param[in]      start
///                 First index of range. Must be at least 0 and at
///                 most ::HAPI_AttributeInfo::count - 1.
///
/// @param[in]      length
///                 Must be at least 0 and at most
///                 ::HAPI_AttributeInfo::count - @p start.
///
HAPI_DECL HAPI_SetAttributeFloatData( const HAPI_Session * session,
                                      HAPI_NodeId node_id,
                                      HAPI_PartId part_id,
                                      const char * name,
                                      const HAPI_AttributeInfo * attr_info,
                                      const float * data_array,
                                      int start, int length );

/// @brief  Set 64-bit attribute float data.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The SOP node id.
///
/// @param[in]      part_id
///                 Currently not used. Just pass 0.
///
/// @param[in]      name
///                 Attribute name.
///
/// @param[in]      attr_info
///                 ::HAPI_AttributeInfo used as input for what tuple size.
///                 you want. Also contains some sanity checks like
///                 data type. Generally should be the same struct
///                 returned by ::HAPI_GetAttributeInfo().
///
/// @param[out]     data_array
///                 An 64-bit float array at least the size of
///                 <tt>length * ::HAPI_AttributeInfo::tupleSize</tt>.
///
/// @param[in]      start
///                 First index of range. Must be at least 0 and at
///                 most ::HAPI_AttributeInfo::count - 1.
///
/// @param[in]      length
///                 Must be at least 0 and at most
///                 ::HAPI_AttributeInfo::count - @p start.
///
HAPI_DECL HAPI_SetAttributeFloat64Data( const HAPI_Session * session,
                                        HAPI_NodeId node_id,
                                        HAPI_PartId part_id,
                                        const char * name,
                                        const HAPI_AttributeInfo * attr_info,
                                        const double * data_array,
                                        int start, int length );

/// @brief  Set attribute string data.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The SOP node id.
///
/// @param[in]      part_id
///                 Currently not used. Just pass 0.
///
/// @param[in]      name
///                 Attribute name.
///
/// @param[in]      attr_info
///                 ::HAPI_AttributeInfo used as input for what tuple size.
///                 you want. Also contains some sanity checks like
///                 data type. Generally should be the same struct
///                 returned by ::HAPI_GetAttributeInfo().
///
/// @param[out]     data_array
///                 An ::HAPI_StringHandle array at least the size of
///                 <tt>length * ::HAPI_AttributeInfo::tupleSize</tt>.
///
/// @param[in]      start
///                 First index of range. Must be at least 0 and at
///                 most ::HAPI_AttributeInfo::count - 1.
///
/// @param[in]      length
///                 Must be at least 0 and at most
///                 ::HAPI_AttributeInfo::count - @p start.
///
HAPI_DECL HAPI_SetAttributeStringData( const HAPI_Session * session,
                                       HAPI_NodeId node_id,
                                       HAPI_PartId part_id,
                                       const char * name,
                                       const HAPI_AttributeInfo *attr_info,
                                       const char ** data_array,
                                       int start, int length );

/// @brief  Add a group to the input geo with the given type and name.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The SOP node id.
///
/// @param[in]      part_id
///                 Currently not used. Just pass 0.
///
/// @param[in]      group_type
///                 The group type.
///
/// @param[in]      group_name
///                 Name of new group to be added.
///
HAPI_DECL HAPI_AddGroup( const HAPI_Session * session,
                         HAPI_NodeId node_id,
                         HAPI_PartId part_id,
                         HAPI_GroupType group_type,
                         const char * group_name );

/// @brief  Remove a group from the input geo with the given type and name.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The SOP node id.
///
/// @param[in]      part_id
///                 Currently not used. Just pass 0.
///
/// @param[in]      group_type
///                 The group type.
///
/// @param[in]      group_name
///                 Name of the group to be removed
///
HAPI_DECL HAPI_DeleteGroup( const HAPI_Session * session,
                         HAPI_NodeId node_id,
                         HAPI_PartId part_id,
                         HAPI_GroupType group_type,
                         const char * group_name );

/// @brief  Set group membership.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The SOP node id.
///
/// @param[in]      part_id
///                 Currently not used. Just pass 0.
///
/// @param[in]      group_type
///                 The group type.
///
/// @param[in]      group_name
///                 The group name.
///
/// @param[in]      membership_array
///                 Array of ints that represent the membership of this
///                 group. Should be the size given by
///                 ::HAPI_PartInfo_GetElementCountByGroupType() with
///                 @p group_type and the ::HAPI_PartInfo of @p part_id.
///
/// @param[in]      start
///                 Start offset into the membership array. Must be
///                 less than ::HAPI_PartInfo_GetElementCountByGroupType().
///
/// @param[in]      length
///                 Should be less than or equal to the size
///                 of @p membership.
///
HAPI_DECL HAPI_SetGroupMembership( const HAPI_Session * session,
                                   HAPI_NodeId node_id,
                                   HAPI_PartId part_id,
                                   HAPI_GroupType group_type,
                                   const char * group_name,
                                   const int * membership_array,
                                   int start, int length );

/// @brief  Commit the current input geometry to the cook engine. Nodes
///         that use this geometry node will re-cook using the input
///         geometry given through the geometry setter API calls.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The SOP node id.
///
HAPI_DECL HAPI_CommitGeo( const HAPI_Session * session,
                          HAPI_NodeId node_id );

/// @brief  Remove all changes that have been committed to this
///         geometry. If this is an intermediate result node (Edit SOP), all
///         deltas will be removed. If it's any other type of node, the node
///         will be unlocked if it is locked.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The SOP node id.
///
HAPI_DECL HAPI_RevertGeo( const HAPI_Session * session,
                          HAPI_NodeId node_id );

// MATERIALS ----------------------------------------------------------------

/// @brief  Get material ids by face/primitive. The material ids returned
///         will be valid as long as the asset is alive. You should query
///         this list after every cook to see if the material assignments
///         have changed. You should also query each material individually
///         using ::HAPI_GetMaterialInfo() to see if it is dirty and needs
///         to be re-imported.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      geometry_node_id
///                 The geometry node id.
///
/// @param[in]      part_id
///                 The part id.
///
/// @param[out]     are_all_the_same
///                 (optional) If true, all faces on this part have the
///                 same material assignment. You can pass NULL here.
///
/// @param[out]     material_ids_array
///                 An array of ::HAPI_NodeId at least the size of
///                 @p length and at most the size of
///                 ::HAPI_PartInfo::faceCount.
///
/// @param[in]      start
///                 The starting index into the list of faces from which
///                 you wish to get the material ids from. Note that
///                 this should be less than ::HAPI_PartInfo::faceCount.
///
/// @param[in]      length
///                 The number of material ids you wish to get. Note that
///                 this should be at most:
///                 ::HAPI_PartInfo::faceCount - @p start.
///
HAPI_DECL HAPI_GetMaterialNodeIdsOnFaces( const HAPI_Session * session,
                                          HAPI_NodeId geometry_node_id,
                                          HAPI_PartId part_id,
                                          HAPI_Bool * are_all_the_same,
                                          HAPI_NodeId * material_ids_array,
                                          int start, int length );

/// @brief  Get the material info.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      material_node_id
///                 The material node id.
///
/// @param[out]     material_info
///                 The returned material info.
///
HAPI_DECL HAPI_GetMaterialInfo( const HAPI_Session * session,
                                HAPI_NodeId material_node_id,
                                HAPI_MaterialInfo * material_info );

/// @brief  Render a single texture from a COP to an image for
///         later extraction.
///
///         Note that you must call this first for any of the other material
///         APIs to work.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      cop_node_id
///                 The COP node id.
///
HAPI_DECL HAPI_RenderCOPToImage( const HAPI_Session * session,
                                 HAPI_NodeId cop_node_id );

/// @brief  Render only a single texture to an image for later extraction.
///         An example use of this method might be to render the diffuse,
///         normal, and bump texture maps of a material to individual
///         texture files for use within the client application.
///
///         Note that you must call this first for any of the other material
///         APIs to work.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      material_node_id
///                 The material node id.
///
/// @param[in]      parm_id
///                 This is the index in the parameter list of the
///                 material_id's node of the parameter containing the
///                 texture map file path.
///
HAPI_DECL HAPI_RenderTextureToImage( const HAPI_Session * session,
                                     HAPI_NodeId material_node_id,
                                     HAPI_ParmId parm_id );

/// @brief  Get information about the image that was just rendered, like
///         resolution and default file format. This information will be
///         used when extracting planes to an image.
///
///         Note that you must call ::HAPI_RenderTextureToImage() first for
///         this method call to make sense.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      material_node_id
///                 The material node id.
///
/// @param[out]     image_info
///                 The struct containing the image information.
///
HAPI_DECL HAPI_GetImageInfo( const HAPI_Session * session,
                             HAPI_NodeId material_node_id,
                             HAPI_ImageInfo * image_info );

/// @brief  Set image information like resolution and file format.
///         This information will be used when extracting planes to
///         an image.
///
///         Note that you must call ::HAPI_RenderTextureToImage() first for
///         this method call to make sense.
///
///         You should also first call ::HAPI_GetImageInfo() to get the
///         current Image Info and change only the properties
///         you don't like.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      material_node_id
///                 The material node id.
///
/// @param[in]      image_info
///                 The struct containing the new image information.
///
HAPI_DECL HAPI_SetImageInfo( const HAPI_Session * session,
                             HAPI_NodeId material_node_id,
                             const HAPI_ImageInfo * image_info );

/// @brief  Get the number of image planes for the just rendered image.
///
///         Note that you must call ::HAPI_RenderTextureToImage() first for
///         this method call to make sense.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      material_node_id
///                 The material node id.
///
/// @param[out]     image_plane_count
///                 The number of image planes.
///
HAPI_DECL HAPI_GetImagePlaneCount( const HAPI_Session * session,
                                   HAPI_NodeId material_node_id,
                                   int * image_plane_count );

/// @brief  Get the names of the image planes of the just rendered image.
///
///         Note that you must call ::HAPI_RenderTextureToImage() first for
///         this method call to make sense.
///
///         You should also call ::HAPI_GetImagePlaneCount() first to get
///         the total number of image planes so you know how large the
///         image_planes string handle array should be.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      material_node_id
///                 The material node id.
///
/// @param[out]     image_planes_array
///                 The image plane names.
///
/// @param[in]      image_plane_count
///                 The number of image planes to get names for. This
///                 must be less than or equal to the count returned
///                 by ::HAPI_GetImagePlaneCount().
///
HAPI_DECL HAPI_GetImagePlanes( const HAPI_Session * session,
                               HAPI_NodeId material_node_id,
                               HAPI_StringHandle * image_planes_array,
                               int image_plane_count );

/// @brief  Extract a rendered image to a file.
///
///         Note that you must call ::HAPI_RenderTextureToImage() first for
///         this method call to make sense.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      material_node_id
///                 The material node id.
///
/// @param[in]      image_file_format_name
///                 The image file format name you wish the image to be
///                 extracted as. You can leave this parameter NULL to
///                 get the image in the original format if it comes from
///                 another texture file or in the default HAPI format,
///                 which is ::HAPI_DEFAULT_IMAGE_FORMAT_NAME, if the image
///                 is generated.
///
///                 You can get some of the very common standard image
///                 file format names from HAPI_Common.h under the
///                 "Defines" section.
///
///                 You can also get a list of all supported file formats
///                 (and the exact names this parameter expects)
///                 by using ::HAPI_GetSupportedImageFileFormats(). This
///                 list will include custom file formats you created via
///                 custom DSOs (see HDK docs about IMG_Format). You will
///                 get back a list of ::HAPI_ImageFileFormat. This
///                 parameter expects the ::HAPI_ImageFileFormat::nameSH
///                 of a given image file format.
///
/// @param[in]      image_planes
///                 The image planes you wish to extract into the file.
///                 Multiple image planes should be separated by spaces.
///
/// @param[in]      destination_folder_path
///                 The folder where the image file should be created.
///
/// @param[in]      destination_file_name
///                 Optional parameter to overwrite the name of the
///                 extracted texture file. This should NOT include
///                 the extension as the file type will be decided
///                 by the ::HAPI_ImageInfo you can set using
///                 ::HAPI_SetImageInfo(). You still have to use
///                 destination_file_path to get the final file path.
///
///                 Pass in NULL to have the file name be automatically
///                 generated from the name of the material SHOP node,
///                 the name of the texture map parameter if the
///                 image was rendered from a texture, and the image
///                 plane names specified.
///
/// @param[out]     destination_file_path
///                 The full path string handle, including the
///                 destination_folder_path and the texture file name,
///                 to the extracted file. Note that this string handle
///                 will only be valid until the next call to
///                 this function.
///
HAPI_DECL HAPI_ExtractImageToFile( const HAPI_Session * session,
                                   HAPI_NodeId material_node_id,
                                   const char * image_file_format_name,
                                   const char * image_planes,
                                   const char * destination_folder_path,
                                   const char * destination_file_name,
                                   int * destination_file_path );

/// @brief  Extract a rendered image to memory.
///
///         Note that you must call ::HAPI_RenderTextureToImage() first for
///         this method call to make sense.
///
///         Also note that this function will do all the work of
///         extracting and compositing the image into a memory buffer
///         but will not return to you that buffer, only its size. Use
///         the returned size to allocated a sufficiently large buffer
///         and call ::HAPI_GetImageMemoryBuffer() to fill your buffer
///         with the just extracted image.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      material_node_id
///                 The material node id.
///
/// @param[in]      image_file_format_name
///                 The image file format name you wish the image to be
///                 extracted as. You can leave this parameter NULL to
///                 get the image in the original format if it comes from
///                 another texture file or in the default HAPI format,
///                 which is ::HAPI_DEFAULT_IMAGE_FORMAT_NAME, if the image
///                 is generated.
///
///                 You can get some of the very common standard image
///                 file format names from HAPI_Common.h under the
///                 "Defines" section.
///
///                 You can also get a list of all supported file formats
///                 (and the exact names this parameter expects)
///                 by using ::HAPI_GetSupportedImageFileFormats(). This
///                 list will include custom file formats you created via
///                 custom DSOs (see HDK docs about IMG_Format). You will
///                 get back a list of ::HAPI_ImageFileFormat. This
///                 parameter expects the ::HAPI_ImageFileFormat::nameSH
///                 of a given image file format.
///
/// @param[in]      image_planes
///                 The image planes you wish to extract into the file.
///                 Multiple image planes should be separated by spaces.
///
/// @param[out]     buffer_size
///                 The extraction will be done to an internal buffer
///                 who's size you get via this parameter. Use the
///                 returned buffer_size when calling
///                 ::HAPI_GetImageMemoryBuffer() to get the image
///                 buffer you just extracted.
///
HAPI_DECL HAPI_ExtractImageToMemory( const HAPI_Session * session,
                                     HAPI_NodeId material_node_id,
                                     const char * image_file_format_name,
                                     const char * image_planes,
                                     int * buffer_size );

/// @brief  Fill your allocated buffer with the just extracted
///         image buffer.
///
///         Note that you must call ::HAPI_RenderTextureToImage() first for
///         this method call to make sense.
///
///         Also note that you must call ::HAPI_ExtractImageToMemory()
///         first in order to perform the extraction and get the
///         extracted image buffer size that you need to know how much
///         memory to allocated to fit your extracted image.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      material_node_id
///                 The material node id.
///
/// @param[out]     buffer
///                 The buffer passed in here will be filled with the
///                 image buffer created during the call to
///                 ::HAPI_ExtractImageToMemory().
///
/// @param[in]      length
///                 Sanity check. This size should be the same as the
///                 size allocated for the buffer passed in and should
///                 be at least as large as the buffer_size returned by
///                 the call to ::HAPI_ExtractImageToMemory().
///
HAPI_DECL HAPI_GetImageMemoryBuffer( const HAPI_Session * session,
                                     HAPI_NodeId material_node_id,
                                     char * buffer, int length );

/// @brief  Get the number of supported texture file formats.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[out]     file_format_count
///                 The number of supported texture file formats.
///
HAPI_DECL HAPI_GetSupportedImageFileFormatCount( const HAPI_Session * session,
                                                 int * file_format_count );

/// @brief  Get a list of support image file formats - their names,
///         descriptions and a list of recognized extensions.
///
///         Note that you MUST call
///         ::HAPI_GetSupportedImageFileFormatCount()
///         before calling this function for the first time.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[out]     formats_array
///                 The list of ::HAPI_ImageFileFormat structs to
///                 be filled.
///
/// @param[in]      file_format_count
///                 The number of supported texture file formats. This
///                 should be at least as large as the count returned
///                 by ::HAPI_GetSupportedImageFileFormatCount().
///
HAPI_DECL HAPI_GetSupportedImageFileFormats(
                                        const HAPI_Session * session,
                                        HAPI_ImageFileFormat * formats_array,
                                        int file_format_count );

// SIMULATION/ANIMATION -----------------------------------------------------

/// @brief  Set an animation curve on a parameter of an exposed node.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The exposed node id.
///
/// @param[in]      parm_id
///                 The id of an exposed parameter within the node.
/// @param[in]      parm_index
///                 The index of the parameter, if it is for example
///                 a 3 tuple
///
/// @param[in]      curve_keyframes_array
///                 An array of ::HAPI_Keyframe structs that describes
///                 the keys on this curve.
///
/// @param[in]      keyframe_count
///                 The number of keys on the curve.
///
HAPI_DECL HAPI_SetAnimCurve( const HAPI_Session * session,
                             HAPI_NodeId node_id, HAPI_ParmId parm_id,
                             int parm_index,
                             const HAPI_Keyframe * curve_keyframes_array,
                             int keyframe_count );

/// @brief  A specialized convenience function to set the T,R,S values
///         on an exposed node.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The exposed node id.
///
/// @param[in]      trans_comp
///                 A value of ::HAPI_TransformComponent that
///                 identifies the particular component of the
///                 transform to attach the curve to, for example
///                 ::HAPI_TRANSFORM_TX.
///
/// @param[in]      curve_keyframes_array
///                 An array of ::HAPI_Keyframe structs that describes
///                 the keys on this curve.
///
/// @param[in]      keyframe_count
///                 The number of keys on the curve.
///
HAPI_DECL HAPI_SetTransformAnimCurve(
                            const HAPI_Session * session,
                            HAPI_NodeId node_id,
                            HAPI_TransformComponent trans_comp,
                            const HAPI_Keyframe * curve_keyframes_array,
                            int keyframe_count );

/// @brief  Resets the simulation cache of the asset.  This is very useful
///         for assets that use dynamics, to be called after some
///         setup has changed for the asset - for example, asset inputs
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The asset node id.
///
HAPI_DECL HAPI_ResetSimulation( const HAPI_Session * session,
                                HAPI_NodeId node_id );

// VOLUMES ------------------------------------------------------------------

/// @brief  Retrieve any meta-data about the volume primitive, including
///         its transform, location, scale, taper, resolution.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      part_id
///                 The part id.
///
/// @param[out]     volume_info
///                 The meta-data associated with the volume on the
///                 part specified by the previous parameters.
///
HAPI_DECL HAPI_GetVolumeInfo( const HAPI_Session * session,
                              HAPI_NodeId node_id,
                              HAPI_PartId part_id,
                              HAPI_VolumeInfo * volume_info );

/// @brief  Iterate through a volume based on 8x8x8 sections of the volume
///         Start iterating through the value of the volume at part_id.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      part_id
///                 The part id.
///
/// @param[out]     tile
///                 The tile info referring to the first tile in the
///                 volume at part_id.
///
HAPI_DECL HAPI_GetFirstVolumeTile( const HAPI_Session * session,
                                   HAPI_NodeId node_id,
                                   HAPI_PartId part_id,
                                   HAPI_VolumeTileInfo * tile );

/// @brief  Iterate through a volume based on 8x8x8 sections of the volume
///         Continue iterating through the value of the volume at part_id.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      part_id
///                 The part id.
///
/// @param[out]     tile
///                 The tile info referring to the next tile in the
///                 set of tiles associated with the volume at this part.
///
HAPI_DECL HAPI_GetNextVolumeTile( const HAPI_Session * session,
                                  HAPI_NodeId node_id,
                                  HAPI_PartId part_id,
                                  HAPI_VolumeTileInfo * tile );

/// @brief  Retrieve floating point values of the voxel at a specific
///         index. Note that you must call ::HAPI_GetVolumeInfo() prior
///         to this call.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      part_id
///                 The part id.
///
/// @param[in]      x_index
///                 The x index/coordinate of the voxel.
///
/// @param[in]      y_index
///                 The y index/coordinate of the voxel.
///
/// @param[in]      z_index
///                 The z index/coordinate of the voxel.
///
/// @param[out]     values_array
///                 The values of the voxel.
///
/// @param[in]      value_count
///                 Should be equal to the volume's
///                 ::HAPI_VolumeInfo::tupleSize.
///
HAPI_DECL HAPI_GetVolumeVoxelFloatData( const HAPI_Session * session,
                                        HAPI_NodeId node_id,
                                        HAPI_PartId part_id,
                                        int x_index,
                                        int y_index,
                                        int z_index,
                                        float * values_array,
                                        int value_count );

/// @brief  Retrieve floating point values of the voxels pointed to
///         by a tile. Note that a tile may extend beyond the limits
///         of the volume so not all values in the given buffer will
///         be written to. Voxels outside the volume will be initialized
///         to the given fill value.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      part_id
///                 The part id.
///
/// @param[in]      fill_value
///                 Value that will be used to fill the @p values_array.
///                 This is useful so that you can see what values
///                 have actually been written to.
///
/// @param[in]      tile
///                 The tile to retrieve.
///
/// @param[out]     values_array
///                 The values of the tile.
///
/// @param[in]      length
///                 The length should be ( 8 ^ 3 ) * tupleSize.
///
HAPI_DECL HAPI_GetVolumeTileFloatData( const HAPI_Session * session,
                                       HAPI_NodeId node_id,
                                       HAPI_PartId part_id,
                                       float fill_value,
                                       const HAPI_VolumeTileInfo * tile,
                                       float * values_array,
                                       int length );

/// @brief  Retrieve integer point values of the voxel at a specific
///         index. Note that you must call ::HAPI_GetVolumeInfo() prior
///         to this call.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      part_id
///                 The part id.
///
/// @param[in]      x_index
///                 The x index/coordinate of the voxel.
///
/// @param[in]      y_index
///                 The y index/coordinate of the voxel.
///
/// @param[in]      z_index
///                 The z index/coordinate of the voxel.
///
/// @param[out]     values_array
///                 The values of the voxel.
///
/// @param[in]      value_count
///                 Should be equal to the volume's
///                 ::HAPI_VolumeInfo::tupleSize.
///
HAPI_DECL HAPI_GetVolumeVoxelIntData( const HAPI_Session * session,
                                      HAPI_NodeId node_id,
                                      HAPI_PartId part_id,
                                      int x_index,
                                      int y_index,
                                      int z_index,
                                      int * values_array,
                                      int value_count );

/// @brief  Retrieve integer point values of the voxels pointed to
///         by a tile. Note that a tile may extend beyond the limits
///         of the volume so not all values in the given buffer will
///         be written to. Voxels outside the volume will be initialized
///         to the given fill value.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      part_id
///                 The part id.
///
/// @param[in]      fill_value
///                 Value that will be used to fill the @p values_array.
///                 This is useful so that you can see what values
///                 have actually been written to.
///
/// @param[in]      tile
///                 The tile to retrieve.
///
/// @param[out]     values_array
///                 The values of the tile.
///
/// @param[in]      length
///                 The length should be ( 8 ^ 3 ) * tupleSize.
///
HAPI_DECL HAPI_GetVolumeTileIntData( const HAPI_Session * session,
                                     HAPI_NodeId node_id,
                                     HAPI_PartId part_id,
                                     int fill_value,
                                     const HAPI_VolumeTileInfo * tile,
                                     int * values_array,
                                     int length );

/// @brief  Get the height field data for a terrain volume as a flattened
///         2D array of float heights. Should call ::HAPI_GetVolumeInfo()
///         first to make sure the volume info is initialized.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      part_id
///                 The part id.
///
/// @param[out]     values_array
///                 Heightfield flattened array. Should be at least the size of
///                 @p start + @p length.
///
/// @param[in]      start
///                 The start at least 0 and at most
///                 ( ::HAPI_VolumeInfo.xLength * ::HAPI_VolumeInfo::yLength )
///                 - @p length.
///
/// @param[in]      length
///                 The length should be at least 1 or at most
///                 ( ::HAPI_VolumeInfo.xLength * ::HAPI_VolumeInfo::yLength )
///                 - @p start.
///
HAPI_DECL HAPI_GetHeightFieldData( const HAPI_Session * session,
                                   HAPI_NodeId node_id,
                                   HAPI_PartId part_id,
                                   float * values_array,
                                   int start, int length );

/// @brief  Set the volume info of a geo on a geo input.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      part_id
///                 The part id.
///
/// @param[in]      volume_info
///                 All volume information that can be specified per
///                 volume. This includes the position, orientation, scale,
///                 data format, tuple size, and taper. The tile size is
///                 always 8x8x8.
///
HAPI_DECL HAPI_SetVolumeInfo( const HAPI_Session * session,
                              HAPI_NodeId node_id,
                              HAPI_PartId part_id,
                              const HAPI_VolumeInfo * volume_info );

/// @brief  Set the values of a float tile: this is an 8x8x8 subsection of
///         the volume.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      part_id
///                 The part id.
///
/// @param[in]      tile
///                 The tile that the volume will be input into.
///
/// @param[in]      values_array
///                 The values of the individual voxel tiles in the
///                 volume. The length of this array should
///                 be ( 8 ^ 3 ) * tupleSize.
///
/// @param[in]      length
///                 The length should be ( 8 ^ 3 ) * tupleSize.
///
HAPI_DECL HAPI_SetVolumeTileFloatData( const HAPI_Session * session,
                                       HAPI_NodeId node_id,
                                       HAPI_PartId part_id,
                                       const HAPI_VolumeTileInfo * tile,
                                       const float * values_array,
                                       int length );

/// @brief  Set the values of an int tile: this is an 8x8x8 subsection of
///         the volume.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      part_id
///                 The part id.
///
/// @param[in]      tile
///                 The tile that the volume will be input into.
///
/// @param[in]      values_array
///                 The values of the individual voxel tiles in the
///                 volume. The length of this array should
///                 be ( 8 ^ 3 ) * tupleSize.
///
/// @param[in]      length
///                 The length should be ( 8 ^ 3 ) * tupleSize.
///
HAPI_DECL HAPI_SetVolumeTileIntData( const HAPI_Session * session,
                                     HAPI_NodeId node_id,
                                     HAPI_PartId part_id,
                                     const HAPI_VolumeTileInfo * tile,
                                     const int * values_array,
                                     int length );

/// @brief  Set the values of a float voxel in the volume.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      part_id
///                 The part id.
///
/// @param[in]      x_index
///                 The x index/coordinate of the voxel.
///
/// @param[in]      y_index
///                 The y index/coordinate of the voxel.
///
/// @param[in]      z_index
///                 The z index/coordinate of the voxel.
///
/// @param[in]     values_array
///                 The values of the voxel.
///
/// @param[in]      value_count
///                 Should be equal to the volume's
///                 ::HAPI_VolumeInfo::tupleSize.
///
HAPI_DECL HAPI_SetVolumeVoxelFloatData( const HAPI_Session * session,
                                        HAPI_NodeId node_id,
                                        HAPI_PartId part_id,
                                        int x_index,
                                        int y_index,
                                        int z_index,
                                        const float * values_array,
                                        int value_count );

/// @brief  Set the values of a integer voxel in the volume.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      part_id
///                 The part id.
///
/// @param[in]      x_index
///                 The x index/coordinate of the voxel.
///
/// @param[in]      y_index
///                 The y index/coordinate of the voxel.
///
/// @param[in]      z_index
///                 The z index/coordinate of the voxel.
///
/// @param[in]     values_array
///                 The values of the voxel.
///
/// @param[in]      value_count
///                 Should be equal to the volume's
///                 ::HAPI_VolumeInfo::tupleSize.
///
HAPI_DECL HAPI_SetVolumeVoxelIntData(   const HAPI_Session * session,
                                        HAPI_NodeId node_id,
                                        HAPI_PartId part_id,
                                        int x_index,
                                        int y_index,
                                        int z_index,
                                        const int * values_array,
                                        int value_count );

/// @brief  Get the bounding values of a volume.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      part_id
///                 The part id.
///
/// @param[out]     x_min
///                 The minimum x value of the volume's bounding box.
///                 Can be null if you do not want this value.
///
/// @param[out]     y_min
///                 The minimum y value of the volume's bounding box.
///                 Can be null if you do not want this value.
///
/// @param[out]     z_min
///                 The minimum z value of the volume's bounding box.
///                 Can be null if you do not want this value.
///
/// @param[out]     x_max
///                 The maximum x value of the volume's bounding box.
///                 Can be null if you do not want this value.
///
/// @param[out]     y_max
///                 The maximum y value of the volume's bounding box.
///                 Can be null if you do not want this value.
///
/// @param[out]     z_max
///                 The maximum z value of the volume's bounding box.
///                 Can be null if you do not want this value.
///
/// @param[out]     x_center
///                 The x value of the volume's bounding box center.
///                 Can be null if you do not want this value.
///
/// @param[out]     y_center
///                 The y value of the volume's bounding box center.
///                 Can be null if you do not want this value.
///
/// @param[out]     z_center
///                 The z value of the volume's bounding box center.
///                 Can be null if you do not want this value.
///
HAPI_DECL HAPI_GetVolumeBounds( const HAPI_Session * session,
                                HAPI_NodeId node_id,
                                HAPI_PartId part_id,
                                float * x_min, float * y_min, float * z_min,
                                float * x_max, float * y_max, float * z_max,
                                float * x_center, float * y_center, float * z_center );

/// @brief  Set the height field data for a terrain volume with the values from
///         a flattened 2D array of float.
///         ::HAPI_SetVolumeInfo() should be called first to make sure that the 
///         volume and its info are initialized.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      part_id
///                 The part id.
///
/// @param[in]     values_array
///                 Heightfield flattened array. Should be at least the size of
///                 @p start + @p length.
///
/// @param[in]      start
///                 The start at least 0 and at most
///                 ( ::HAPI_VolumeInfo.xLength * ::HAPI_VolumeInfo::yLength )
///                 - @p length.
///
/// @param[in]      length
///                 The length should be at least 1 or at most
///                 ( ::HAPI_VolumeInfo.xLength * ::HAPI_VolumeInfo::yLength )
///                 - @p start.
///
/// @param[in]      name
///                 The name of the volume used for the heightfield.
///                 If set to "height" the values will be used for height information,
///                 if not, the data will used as a mask.
///
HAPI_DECL HAPI_SetHeightFieldData(  const HAPI_Session * session,
                                    HAPI_NodeId node_id,
                                    HAPI_PartId part_id,
                                    const char * name,
                                    const float * values_array,
                                    int start, int length );

// CURVES -------------------------------------------------------------------

/// @brief  Retrieve any meta-data about the curves, including the
///         curve's type, order, and periodicity.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      part_id
///                 The part id.
///
/// @param[out]     info
///                 The curve info represents the meta-data about
///                 the curves, including the type, order,
///                 and periodicity.
///
HAPI_DECL HAPI_GetCurveInfo( const HAPI_Session * session,
                             HAPI_NodeId node_id,
                             HAPI_PartId part_id,
                             HAPI_CurveInfo * info );

/// @brief  Retrieve the number of vertices for each curve in the part.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      part_id
///                 The part id.
///
/// @param[out]     counts_array
///                 The number of cvs each curve contains
///
/// @param[in]      start
///                 The index of the first curve.
///
/// @param[in]      length
///                 The number of curves' counts to retrieve.
///
HAPI_DECL HAPI_GetCurveCounts( const HAPI_Session * session,
                               HAPI_NodeId node_id,
                               HAPI_PartId part_id,
                               int * counts_array,
                               int start, int length );

/// @brief  Retrieve the orders for each curve in the part if the
///         curve has varying order.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      part_id
///                 The part id.
///
/// @param[out]     orders_array
///                 The order of each curve will be returned in this
///                 array.
///
/// @param[in]      start
///                 The index of the first curve.
///
/// @param[in]      length
///                 The number of curves' orders to retrieve.
///
HAPI_DECL HAPI_GetCurveOrders( const HAPI_Session * session,
                               HAPI_NodeId node_id,
                               HAPI_PartId part_id,
                               int * orders_array,
                               int start, int length );

/// @brief  Retrieve the knots of the curves in this part.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      part_id
///                 The part id.
///
/// @param[out]     knots_array
///                 The knots of each curve will be returned in this
///                 array.
///
/// @param[in]      start
///                 The index of the first curve.
///
/// @param[in]      length
///                 The number of curves' knots to retrieve. The
///                 length of all the knots on a single curve is
///                 the order of that curve plus the number of
///                 vertices (see ::HAPI_GetCurveOrders(),
///                 and ::HAPI_GetCurveCounts()).
///
HAPI_DECL HAPI_GetCurveKnots( const HAPI_Session * session,
                              HAPI_NodeId node_id,
                              HAPI_PartId part_id,
                              float * knots_array,
                              int start, int length );

/// @brief  Set meta-data for the curve mesh, including the
///         curve type, order, and periodicity.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      part_id
///                 Currently unused. Input asset geos are assumed
///                 to have only one part.
///
/// @param[in]      info
///                 The curve info represents the meta-data about
///                 the curves, including the type, order,
///                 and periodicity.
///
HAPI_DECL HAPI_SetCurveInfo( const HAPI_Session * session,
                             HAPI_NodeId node_id,
                             HAPI_PartId part_id,
                             const HAPI_CurveInfo * info );

/// @brief  Set the number of vertices for each curve in the part.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      part_id
///                 Currently unused. Input asset geos are assumed
///                 to have only one part.
///
/// @param[in]      counts_array
///                 The number of cvs each curve contains.
///
/// @param[in]      start
///                 The index of the first curve.
///
/// @param[in]      length
///                 The number of curves' counts to set.
///
HAPI_DECL HAPI_SetCurveCounts( const HAPI_Session * session,
                               HAPI_NodeId node_id,
                               HAPI_PartId part_id,
                               const int * counts_array,
                               int start, int length );

/// @brief  Set the orders for each curve in the part if the
///         curve has varying order.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      part_id
///                 Currently unused. Input asset geos are assumed
///                 to have only one part.
///
/// @param[in]      orders_array
///                 The orders of each curve.
///
/// @param[in]      start
///                 The index of the first curve.
///
/// @param[in]      length
///                 The number of curves' orders to retrieve.
///
HAPI_DECL HAPI_SetCurveOrders( const HAPI_Session * session,
                               HAPI_NodeId node_id,
                               HAPI_PartId part_id,
                               const int * orders_array,
                               int start, int length );

/// @brief  Set the knots of the curves in this part.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      part_id
///                 Currently unused. Input asset geos are assumed
///                 to have only one part.
///
/// @param[in]      knots_array
///                 The knots of each curve.
///
/// @param[in]      start
///                 The index of the first curve.
///
/// @param[in]      length
///                 The number of curves' knots to set. The
///                 length of all the knots on a single curve is
///                 the order of that curve plus the number of
///                 vertices (see ::HAPI_SetCurveOrders(),
///                 and ::HAPI_SetCurveCounts()).
///
HAPI_DECL HAPI_SetCurveKnots( const HAPI_Session * session,
                              HAPI_NodeId node_id,
                              HAPI_PartId part_id,
                              const float * knots_array,
                              int start, int length );

// BASIC PRIMITIVES ---------------------------------------------------------

/// @brief  Get the box info on a geo part (if the part is a box).
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      geo_node_id
///                 The geo node id.
///
/// @param[in]      part_id
///                 The part id of the
///
/// @param[out]     box_info
///                 The returned box info.
///
HAPI_DECL HAPI_GetBoxInfo( const HAPI_Session * session,
                           HAPI_NodeId geo_node_id,
                           HAPI_PartId part_id,
                           HAPI_BoxInfo * box_info );

/// @brief  Get the sphere info on a geo part (if the part is a sphere).
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      geo_node_id
///                 The geo node id.
///
/// @param[in]      part_id
///                 The part id of the
///
/// @param[out]     sphere_info
///                 The returned sphere info.
///
HAPI_DECL HAPI_GetSphereInfo( const HAPI_Session * session,
                              HAPI_NodeId geo_node_id,
                              HAPI_PartId part_id,
                              HAPI_SphereInfo * sphere_info );

// CACHING ------------------------------------------------------------------

/// @brief  Get the number of currently active caches.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[out]     active_cache_count
///                 The number of currently active caches.
///
HAPI_DECL HAPI_GetActiveCacheCount( const HAPI_Session * session,
                                    int * active_cache_count );

/// @brief  Get the names of the currently active caches.
///
///         Requires a valid active cache count which you get from:
///         ::HAPI_GetActiveCacheCount().
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[out]     cache_names_array
///                 String array with the returned cache names. Must be
///                 at least the size of @a active_cache_count.
///
/// @param[in]      active_cache_count
///                 The count returned by ::HAPI_GetActiveCacheCount().
///
HAPI_DECL HAPI_GetActiveCacheNames( const HAPI_Session * session,
                                    HAPI_StringHandle * cache_names_array,
                                    int active_cache_count );

/// @brief  Lets you inspect specific properties of the different memory
///         caches in the current Houdini context.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      cache_name
///                 Cache name from ::HAPI_GetActiveCacheNames().
///
/// @param[in]      cache_property
///                 The specific property of the cache to get the value for.
///
/// @param[out]     property_value
///                 Returned property value.
///
HAPI_DECL HAPI_GetCacheProperty( const HAPI_Session * session,
                                 const char * cache_name,
                                 HAPI_CacheProperty cache_property,
                                 int * property_value );

/// @brief  Lets you modify specific properties of the different memory
///         caches in the current Houdini context. This includes clearing
///         caches, reducing their memory use, or changing how memory limits
///         are respected by a cache.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      cache_name
///                 Cache name from ::HAPI_GetActiveCacheNames().
///
/// @param[in]      cache_property
///                 The specific property of the cache to modify.
///
/// @param[in]      property_value
///                 The new property value.
///
HAPI_DECL HAPI_SetCacheProperty( const HAPI_Session * session,
                                 const char * cache_name,
                                 HAPI_CacheProperty cache_property,
                                 int property_value );

/// @brief  Saves a geometry to file.  The type of file to save is
///         to be determined by the extension ie. .bgeo, .obj
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      file_name
///                 The name of the file to be saved.  The extension
///                 of the file determines its type.
///
HAPI_DECL HAPI_SaveGeoToFile( const HAPI_Session * session,
                              HAPI_NodeId node_id,
                              const char * file_name );

/// @brief  Loads a geometry file and put its contents onto a SOP
///         node.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      file_name
///                 The name of the file to be loaded
///
HAPI_DECL HAPI_LoadGeoFromFile( const HAPI_Session * session,
                                HAPI_NodeId node_id,
                                const char * file_name );

/// @brief  Cache the current state of the geo to memory, given the
///         format, and return the size. Use this size with your call
///         to ::HAPI_SaveGeoToMemory() to copy the cached geo to your
///         buffer. It is guaranteed that the size will not change between
///         your call to ::HAPI_GetGeoSize() and ::HAPI_SaveGeoToMemory().
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      format
///                 The file format, ie. ".obj", ".bgeo.sc" etc.
///
/// @param[out]     size
///                 The size of the buffer required to hold the output.
///
HAPI_DECL HAPI_GetGeoSize( const HAPI_Session * session,
                           HAPI_NodeId node_id,
                           const char * format,
                           int * size );

/// @brief  Saves the cached geometry to your buffer in memory,
///         whose format and required size is identified by the call to
///         ::HAPI_GetGeoSize(). The call to ::HAPI_GetGeoSize() is
///         required as ::HAPI_GetGeoSize() does the actual saving work.
///
///         Also note that this call to ::HAPI_SaveGeoToMemory will delete
///         the internal geo buffer that was cached in the previous call
///         to ::HAPI_GetGeoSize(). This means that you will need to call
///         ::HAPI_GetGeoSize() again before you can call this function.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[out]     buffer
///                 The buffer we will write into.
///
/// @param[in]      length
///                 The size of the buffer passed in.
///
HAPI_DECL HAPI_SaveGeoToMemory( const HAPI_Session * session,
                                HAPI_NodeId node_id,
                                char * buffer,
                                int length );

/// @brief  Loads a geometry from memory and put its
///         contents onto a SOP node.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      format
///                 The file format, ie. "obj", "bgeo" etc.
///
/// @param[in]      buffer
///                 The buffer we will read the geometry from.
///
/// @param[in]      length
///                 The size of the buffer passed in.
///
HAPI_DECL HAPI_LoadGeoFromMemory( const HAPI_Session * session,
                                  HAPI_NodeId node_id,
                                  const char * format,
                                  const char * buffer,
                                  int length );

// @brief  Return an array of PDG graph context names and ids, the first 
///        count names will be returned.  These ids can be used 
///        with ::HAPI_GetPDGEvents and ::HAPI_GetPDGState.  The values
///        of the names can be retrieved with ::HAPI_GetString.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[out]     num_contexts
///                 Total number of PDG graph contexts found.
///
/// @param[out]     context_names_array
///                 Array of int (string handles) to house the
///                 context names.  These handles are valid until the next
///                 call to this function.
///
/// @param[out]     context_id_array
///                 Array of graph context ids.
///
/// @param[in]      count
///                 Length of context_names_array and context_id_array
///
HAPI_DECL HAPI_GetPDGGraphContexts( const HAPI_Session * session,
                                    int * num_contexts,
                                    HAPI_StringHandle * context_names_array,
                                    HAPI_PDG_GraphContextId * context_id_array,
                                    int count );

// @brief  Starts a PDG cooking operation.  This can be asynchronous.  
///        Progress can be checked with ::HAPI_GetPDGState and ::HAPI_GetPDGState.
///        Events generated during this cook can be collected with ::HAPI_GetPDGEvents.
///        Any uncollected events will be discarded at the start of the cook.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      cook_node_id
///                 The node id of a TOP node for the cook operation.
///
/// @param[in]      generate_only
///                 1 means only root generation will done.  0 means start
///                 a full graph cook.
///
/// @param[in]      blocking
///                 0 means return immediately and cooking will be done 
///                 asynchronously.   1 means return when cooking completes.
///
HAPI_DECL HAPI_CookPDG( const HAPI_Session * session,
                        HAPI_NodeId cook_node_id,
                        int generate_only,
                        int blocking );

// @brief  Returns PDG events that have been collected.  Calling this function
///        will remove those events from the queue.  Events collection is restarted
///        by calls to ::HAPI_CookPDG.
///
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      graph_context_id
///                 The id of the graph context 
///
/// @param[out]     event_array
///                 buffer of ::HAPI_PDG_EventInfo of size at least length.
///
/// @param[in]      length
///                 The size of the buffer passed in.
///
/// @param[out]     event_count
///                 Number of events removed from queue and copied to buffer.
///
/// @param[out]     remaining_events
///                 Number of queued events remaining after this operation.
///
HAPI_DECL HAPI_GetPDGEvents( const HAPI_Session * session,
                             HAPI_PDG_GraphContextId graph_context_id,
                             HAPI_PDG_EventInfo * event_array,
                             int length,
                             int * event_count,
                             int * remaining_events );

// @brief  Gets the state of a PDG graph
///
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      graph_context_id
///                 The graph context id
///
/// @param[out]     pdg_state
///                 One of ::HAPI_PDG_State.
///
HAPI_DECL HAPI_GetPDGState( const HAPI_Session * session, 
                            HAPI_PDG_GraphContextId graph_context_id, 
                            int * pdg_state );


// @brief  Creates a new pending workitem for the given node.  The workitem
///        will not be submitted to the graph until it is committed with 
///        ::HAPI_CommitWorkitems.  The node is expected to be a generator type.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[out]     workitem_id
///                 The id of the pending workitem.
///
/// @param[in]      name
///                 The null-terminated name of the workitem.  The name will
///                 be automatically suffixed to make it unique.
///
/// @param[in]      index
///                 The index of the workitem.  The semantics of the index
///                 are user defined.
///
HAPI_DECL HAPI_CreateWorkitem( const HAPI_Session * session,
                               HAPI_NodeId node_id,
                               HAPI_PDG_WorkitemId * workitem_id,
                               const char * name,
                               int index );

// @brief  Retrieves the info of a given workitem by id.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      graph_context_id
///                 The graph context that the workitem is in.
///
/// @param[in]      workitem_id
///                 The id of the workitem.
///
/// @param[out]     workitem_info
///                 The returned ::HAPI_PDG_WorkitemInfo for the workitem.  Note
///                 that the enclosed string handle is only valid until the next
///                 call to this function.
///
HAPI_DECL HAPI_GetWorkitemInfo( const HAPI_Session * session,
                                HAPI_PDG_GraphContextId graph_context_id,
                                HAPI_PDG_WorkitemId workitem_id,
                                HAPI_PDG_WorkitemInfo * workitem_info );

// @brief  Adds integer data to a pending PDG workitem data member for the given node.
///
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[out]     workitem_id
///                 The id of the pending workitem returned by ::HAPI_CreateWorkitem
///
/// @param[in]      data_name
///                 null-terminated name of the data member
///
/// @param[in]      values_array
///                 array of integer values
///
/// @param[in]      length
///                 number of values to copy from values_array to the parameter
///
HAPI_DECL HAPI_SetWorkitemIntData( const HAPI_Session * session,
                                   HAPI_NodeId node_id,
                                   HAPI_PDG_WorkitemId workitem_id,
                                   const char * data_name,
                                   const int * values_array,
                                   int length );

// @brief  Adds float data to a pending PDG workitem data member for the given node.
///
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[out]     workitem_id
///                 The id of the pending workitem returned by ::HAPI_CreateWorkitem
///
/// @param[in]      data_name
///                 null-terminated name of the workitem data member
///
/// @param[in]      values_array
///                 array of float values
///
/// @param[in]      length
///                 number of values to copy from values_array to the parameter
///
HAPI_DECL HAPI_SetWorkitemFloatData( const HAPI_Session * session,
                                     HAPI_NodeId node_id,
                                     HAPI_PDG_WorkitemId workitem_id,
                                     const char * data_name,
                                     const float * values_array,
                                     int length );

// @brief  Adds integer data to a pending PDG workitem data member for the given node.
///
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[out]     workitem_id
///                 The id of the created workitem returned by HAPI_CreateWorkitem
///
/// @param[in]      data_name
///                 null-terminated name of the data member
///
/// @param[in]      data_index
///                 index of the string data member
///
/// @param[in]      value
///                 null-terminated string to copy to the workitem data member
///
HAPI_DECL HAPI_SetWorkitemStringData( const HAPI_Session * session,
                                      HAPI_NodeId node_id,
                                      HAPI_PDG_WorkitemId workitem_id,
                                      const char * data_name,
                                      int data_index,
                                      const char * value );

// @brief  Commits any pending workitems.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id for which the pending workitems have been
///                 created but not yet injected.
///
HAPI_DECL HAPI_CommitWorkitems( const HAPI_Session * session,
                                HAPI_NodeId node_id );

// @brief  Gets the number of workitems that are available on the given node.
///        Should be used with ::HAPI_GetWorkitems.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[out]     num
///                 The number of workitems.
///
HAPI_DECL HAPI_GetNumWorkitems( const HAPI_Session * session,
                                HAPI_NodeId node_id,
                                int * num );

// @brief  Gets the list of work item ids for the given node
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[out]     workitem_ids
///                 buffer for resulting array of ::HAPI_PDG_WorkitemId
///
/// @param[in]      length
///                 The length of the workitem_ids buffer
///
HAPI_DECL HAPI_GetWorkitems( const HAPI_Session * session,
                             HAPI_NodeId node_id,
                             int * workitem_ids, int length );

// @brief  Gets the length of the workitem data member.
///        It is the length of the array of data.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      workitem_id
///                 The id of the workitem
///
/// @param[in]      data_name
///                 null-terminated name of the data member
///
/// @param[out]     length
///                 The length of the data member array
///
HAPI_DECL HAPI_GetWorkitemDataLength( const HAPI_Session * session,
                                      HAPI_NodeId node_id,
                                      HAPI_PDG_WorkitemId workitem_id,
                                      const char * data_name,
                                      int * length );

// @brief  Gets int data from a work item member.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      workitem_id
///                 The id of the workitem
///
/// @param[in]      data_name
///                 null-terminated name of the data member
///
/// @param[out]     data_array
///                 buffer of at least size length to copy the data into.  The required
///                 length should be determined by HAPI_GetWorkitemDataLength.
///
/// @param[in]      length
///                 The length of the supplied buffer
///
HAPI_DECL HAPI_GetWorkitemIntData( const HAPI_Session * session,
                                   HAPI_NodeId node_id,
                                   HAPI_PDG_WorkitemId workitem_id,
                                   const char* data_name,
                                   int * data_array,
                                   int length );

// @brief  Gets float data from a work item member.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      workitem_id
///                 The id of the workitem
///
/// @param[in]      data_name
///                 null-terminated name of the data member
///
/// @param[out]     data_array
///                 buffer of at least size length to copy the data into.  The required
///                 length should be determined by HAPI_GetWorkitemDataLength.
///
/// @param[in]      length
///                 The length of the supplied buffer
///
HAPI_DECL HAPI_GetWorkitemFloatData( const HAPI_Session * session,
                                     HAPI_NodeId node_id,
                                     HAPI_PDG_WorkitemId workitem_id,
                                     const char * data_name,
                                     float * data_array,
                                     int length );

// @brief  Gets string ids from a work item member.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      workitem_id
///                 The id of the workitem
///
/// @param[in]      data_name
///                 null-terminated name of the data member
///
/// @param[out]     data_array
///                 buffer of at least size length to copy the data into.  The required
///                 length should be determined by HAPI_GetWorkitemDataLength.  The data
///                 is an array of HAPI_StringHandle which can be used with 
///                 HAPI_GetString.  The string handles are valid until the next call to 
///                 this function.
///
/// @param[in]      length
///                 The length of the supplied buffer
///
HAPI_DECL HAPI_GetWorkitemStringData( const HAPI_Session * session,
                                      HAPI_NodeId node_id,
                                      HAPI_PDG_WorkitemId workitem_id,
                                      const char * data_name,
                                      HAPI_StringHandle * data_array,
                                      int length );                               

// @brief  Gets the info for workitem results.
///        The number of workitem results is found on the ::HAPI_PDG_WorkitemInfo
///        returned by HAPI_GetWorkitemInfo.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[in]      workitem_id
///                 The id of the workitem
///
/// @param[in]      resultinfo_array
///                 buffer to fill with info structs.  String handles are valid
///                 until the next call of this function.
///
/// @param[out]     resultinfo_count
///                 The length of resultinfo_array
///
HAPI_DECL HAPI_GetWorkitemResultInfo( const HAPI_Session * session,
				      HAPI_NodeId node_id,
				      HAPI_PDG_WorkitemId workitem_id,
				      HAPI_PDG_WorkitemResultInfo * resultinfo_array,
				      int resultinfo_count );

// @brief  Dirties the given node.  Cancels the cook if necessary and then
///         deletes all workitems on the node.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      node_id
///                 The node id.
///
/// @param[out]     clean_results
///                 Remove the results generated by the node.
///
HAPI_DECL HAPI_DirtyPDGNode( const HAPI_Session * session, 
			     HAPI_NodeId node_id,
			     HAPI_Bool clean_results );

// @brief  Pause the PDG cooking operation.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      graph_context_id
///                 The id of the graph context
///
HAPI_DECL HAPI_PausePDGCook( const HAPI_Session * session,
                         HAPI_PDG_GraphContextId graph_context_id );

// @brief  Cancel the PDG cooking operation.
///
/// @param[in]      session
///                 The session of Houdini you are interacting with.
///                 See @ref HAPI_Sessions for more on sessions.
///                 Pass NULL to just use the default in-process session.
///
/// @param[in]      graph_context_id
///                 The id of the graph context
///
HAPI_DECL HAPI_CancelPDGCook( const HAPI_Session * session,
                            HAPI_PDG_GraphContextId graph_context_id );

#endif // __HAPI_h__
