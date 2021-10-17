#include "bcos_sdk_c_rpc.h"
#include <bcos-cpp-sdk/rpc/JsonRpcInterface.h>

#include <memory>
#include <tuple>

// ------------------------common send message interface begin----------------
// send message to rpc server
void bcos_rpc_send_msg(void *rpc, const char *data, rpc_callback callback,
                       void *context) {
  auto rpcPointer = (bcos::cppsdk::jsonrpc::JsonRpcInterface *)rpc;

  rpcPointer->genericMethod(
      data, [callback, context](bcos::Error::Ptr error,
                                std::shared_ptr<bcos::bytes> resp) {
        bcos_rpc_handle_response(error ? error.get() : NULL,
                                 resp ? resp.get() : NULL, callback, context);
        ;
      });
}

// send message to group
void bcos_rpc_send_msg_to_group(void *rpc, const char *group, const char *data,
                                rpc_callback callback, void *context) {
  auto rpcPointer = (bcos::cppsdk::jsonrpc::JsonRpcInterface *)rpc;

  rpcPointer->genericMethod(
      group, data,
      [callback, context](bcos::Error::Ptr error,
                          std::shared_ptr<bcos::bytes> resp) {
        bcos_rpc_handle_response(error ? error.get() : NULL,
                                 resp ? resp.get() : NULL, callback, context);
      });
}

// send message to group of node
void bcos_rpc_send_msg_to_group_node(void *rpc, const char *group,
                                     const char *node, const char *data,
                                     rpc_callback callback, void *context) {
  auto rpcPointer = (bcos::cppsdk::jsonrpc::JsonRpcInterface *)rpc;

  rpcPointer->genericMethod(
      group, node, data,
      [callback, context](bcos::Error::Ptr error,
                          std::shared_ptr<bcos::bytes> resp) {
        bcos_rpc_handle_response(error ? error.get() : NULL,
                                 resp ? resp.get() : NULL, callback, context);
        ;
      });
}
// ------------------------common send message interface end----------------

// ------------------------------rpc interface begin -------------------------
// call
void bcos_rpc_call(void *rpc, const char *group, const char *to,
                   const char *data, rpc_callback callback, void *context) {
  auto rpcPointer = (bcos::cppsdk::jsonrpc::JsonRpcInterface *)rpc;

  rpcPointer->call(group, to, data,
                   [callback, context](bcos::Error::Ptr error,
                                       std::shared_ptr<bcos::bytes> resp) {
                     bcos_rpc_handle_response(error ? error.get() : NULL,
                                              resp ? resp.get() : NULL,
                                              callback, context);
                     ;
                   });
}

// sendTransaction
void bcos_rpc_send_transaction(void *rpc, const char *group, const char *data,
                               bool proof, rpc_callback callback,
                               void *context) {
  auto rpcPointer = (bcos::cppsdk::jsonrpc::JsonRpcInterface *)rpc;

  rpcPointer->sendTransaction(
      group, data, proof,
      [callback, context](bcos::Error::Ptr error,
                          std::shared_ptr<bcos::bytes> resp) {
        bcos_rpc_handle_response(error ? error.get() : NULL,
                                 resp ? resp.get() : NULL, callback, context);
        ;
      });
}

// getTransaction
void bcos_rpc_get_transaction(void *rpc, const char *group, const char *tx_hash,
                              bool proof, rpc_callback callback,
                              void *context) {
  auto rpcPointer = (bcos::cppsdk::jsonrpc::JsonRpcInterface *)rpc;

  rpcPointer->getTransaction(
      group, tx_hash, proof,
      [callback, context](bcos::Error::Ptr error,
                          std::shared_ptr<bcos::bytes> resp) {
        bcos_rpc_handle_response(error ? error.get() : NULL,
                                 resp ? resp.get() : NULL, callback, context);
        ;
      });
}

// getTransactionReceipt
void bcos_rpc_get_transaction_receipt(void *rpc, const char *group,
                                      const char *tx_hash, bool proof,
                                      rpc_callback callback, void *context) {
  auto rpcPointer = (bcos::cppsdk::jsonrpc::JsonRpcInterface *)rpc;

  rpcPointer->getTransactionReceipt(
      group, tx_hash, proof,
      [callback, context](bcos::Error::Ptr error,
                          std::shared_ptr<bcos::bytes> resp) {
        bcos_rpc_handle_response(error ? error.get() : NULL,
                                 resp ? resp.get() : NULL, callback, context);
        ;
      });
}

// getBlockByHash
void bcos_rpc_get_block_by_hash(void *rpc, const char *group,
                                const char *block_hash, bool only_header,
                                bool only_tx_hash, rpc_callback callback,
                                void *context) {
  auto rpcPointer = (bcos::cppsdk::jsonrpc::JsonRpcInterface *)rpc;

  rpcPointer->getBlockByHash(
      group, block_hash, only_header, only_tx_hash,
      [callback, context](bcos::Error::Ptr error,
                          std::shared_ptr<bcos::bytes> resp) {
        bcos_rpc_handle_response(error ? error.get() : NULL,
                                 resp ? resp.get() : NULL, callback, context);
        ;
      });
}

// getBlockByNumber
void bcos_rpc_get_block_by_number(void *rpc, const char *group,
                                  int64_t block_number, bool only_header,
                                  bool only_tx_hash, rpc_callback callback,
                                  void *context) {
  auto rpcPointer = (bcos::cppsdk::jsonrpc::JsonRpcInterface *)rpc;

  rpcPointer->getBlockByNumber(
      group, block_number, only_header, only_tx_hash,
      [callback, context](bcos::Error::Ptr error,
                          std::shared_ptr<bcos::bytes> resp) {
        bcos_rpc_handle_response(error ? error.get() : NULL,
                                 resp ? resp.get() : NULL, callback, context);
        ;
      });
}

// getBlockHashByNumber
void bcos_rpc_get_block_hash_by_number(void *rpc, const char *group,
                                       int64_t block_number,
                                       rpc_callback callback, void *context) {
  auto rpcPointer = (bcos::cppsdk::jsonrpc::JsonRpcInterface *)rpc;

  rpcPointer->getBlockHashByNumber(
      group, block_number,
      [callback, context](bcos::Error::Ptr error,
                          std::shared_ptr<bcos::bytes> resp) {
        bcos_rpc_handle_response(error ? error.get() : NULL,
                                 resp ? resp.get() : NULL, callback, context);
        ;
      });
}
// getBlockNumber
void bcos_rpc_get_block_number(void *rpc, const char *group,
                               rpc_callback callback, void *context) {
  auto rpcPointer = (bcos::cppsdk::jsonrpc::JsonRpcInterface *)rpc;

  rpcPointer->getBlockNumber(
      group, [callback, context](bcos::Error::Ptr error,
                                 std::shared_ptr<bcos::bytes> resp) {
        bcos_rpc_handle_response(error ? error.get() : NULL,
                                 resp ? resp.get() : NULL, callback, context);
        ;
      });
}

// getCode
void bcos_rpc_get_code(void *rpc, const char *group, const char *address,
                       rpc_callback callback, void *context) {
  auto rpcPointer = (bcos::cppsdk::jsonrpc::JsonRpcInterface *)rpc;

  rpcPointer->getCode(group, address,
                      [callback, context](bcos::Error::Ptr error,
                                          std::shared_ptr<bcos::bytes> resp) {
                        bcos_rpc_handle_response(error ? error.get() : NULL,
                                                 resp ? resp.get() : NULL,
                                                 callback, context);
                      });
}

// getSealerList
void bcos_rpc_get_sealer_list(void *rpc, const char *group,
                              rpc_callback callback, void *context) {
  auto rpcPointer = (bcos::cppsdk::jsonrpc::JsonRpcInterface *)rpc;

  rpcPointer->getSealerList(
      group, [callback, context](bcos::Error::Ptr error,
                                 std::shared_ptr<bcos::bytes> resp) {
        bcos_rpc_handle_response(error ? error.get() : NULL,
                                 resp ? resp.get() : NULL, callback, context);
        ;
      });
}

// getObserverList
void bcos_rpc_get_observer_list(void *rpc, const char *group,
                                rpc_callback callback, void *context) {
  auto rpcPointer = (bcos::cppsdk::jsonrpc::JsonRpcInterface *)rpc;

  rpcPointer->getObserverList(
      group, [callback, context](bcos::Error::Ptr error,
                                 std::shared_ptr<bcos::bytes> resp) {
        bcos_rpc_handle_response(error ? error.get() : NULL,
                                 resp ? resp.get() : NULL, callback, context);
        ;
      });
}

// getPbftView
void bcos_rpc_get_pbft_view(void *rpc, const char *group, rpc_callback callback,
                            void *context) {
  auto rpcPointer = (bcos::cppsdk::jsonrpc::JsonRpcInterface *)rpc;

  rpcPointer->getPbftView(
      group, [callback, context](bcos::Error::Ptr error,
                                 std::shared_ptr<bcos::bytes> resp) {
        bcos_rpc_handle_response(error ? error.get() : NULL,
                                 resp ? resp.get() : NULL, callback, context);
        ;
      });
}

// getPendingTxSize
void bcos_rpc_get_pending_tx_size(void *rpc, const char *group,
                                  rpc_callback callback, void *context) {
  auto rpcPointer = (bcos::cppsdk::jsonrpc::JsonRpcInterface *)rpc;

  rpcPointer->getPendingTxSize(
      group, [callback, context](bcos::Error::Ptr error,
                                 std::shared_ptr<bcos::bytes> resp) {
        bcos_rpc_handle_response(error ? error.get() : NULL,
                                 resp ? resp.get() : NULL, callback, context);
        ;
      });
}

// getSyncStatus
void bcos_rpc_get_sync_status(void *rpc, const char *group,
                              rpc_callback callback, void *context) {
  auto rpcPointer = (bcos::cppsdk::jsonrpc::JsonRpcInterface *)rpc;

  rpcPointer->getSyncStatus(
      group, [callback, context](bcos::Error::Ptr error,
                                 std::shared_ptr<bcos::bytes> resp) {
        bcos_rpc_handle_response(error ? error.get() : NULL,
                                 resp ? resp.get() : NULL, callback, context);
        ;
      });
}

// getConsensusStatus
void bcos_rpc_get_consensus_status(void *rpc, const char *group,
                                   rpc_callback callback, void *context) {
  auto rpcPointer = (bcos::cppsdk::jsonrpc::JsonRpcInterface *)rpc;

  rpcPointer->getConsensusStatus(
      group, [callback, context](bcos::Error::Ptr error,
                                 std::shared_ptr<bcos::bytes> resp) {
        bcos_rpc_handle_response(error ? error.get() : NULL,
                                 resp ? resp.get() : NULL, callback, context);
        ;
      });
}

// getSystemConfigByKey
void bcos_rpc_get_system_config_by_key(void *rpc, const char *group,
                                       const char *key, rpc_callback callback,
                                       void *context) {
  auto rpcPointer = (bcos::cppsdk::jsonrpc::JsonRpcInterface *)rpc;

  rpcPointer->getSystemConfigByKey(
      group, key,
      [callback, context](bcos::Error::Ptr error,
                          std::shared_ptr<bcos::bytes> resp) {
        bcos_rpc_handle_response(error ? error.get() : NULL,
                                 resp ? resp.get() : NULL, callback, context);
        ;
      });
}

// getTotalTransactionCount
void bcos_rpc_get_total_transaction_count(void *rpc, const char *group,
                                          rpc_callback callback,
                                          void *context) {
  auto rpcPointer = (bcos::cppsdk::jsonrpc::JsonRpcInterface *)rpc;

  rpcPointer->getTotalTransactionCount(
      group, [callback, context](bcos::Error::Ptr error,
                                 std::shared_ptr<bcos::bytes> resp) {
        bcos_rpc_handle_response(error ? error.get() : NULL,
                                 resp ? resp.get() : NULL, callback, context);
        ;
      });
}

// getPeers
void bcos_rpc_get_peers(void *rpc, rpc_callback callback, void *context) {
  auto rpcPointer = (bcos::cppsdk::jsonrpc::JsonRpcInterface *)rpc;

  rpcPointer->getPeers([callback, context](bcos::Error::Ptr error,
                                           std::shared_ptr<bcos::bytes> resp) {
    bcos_rpc_handle_response(error ? error.get() : NULL,
                             resp ? resp.get() : NULL, callback, context);
    ;
  });
}

// createGroup
void bcos_rpc_create_group(void *rpc, const char *group_info,
                           rpc_callback callback, void *context) {
  auto rpcPointer = (bcos::cppsdk::jsonrpc::JsonRpcInterface *)rpc;

  rpcPointer->createGroup(
      group_info, [callback, context](bcos::Error::Ptr error,
                                      std::shared_ptr<bcos::bytes> resp) {
        bcos_rpc_handle_response(error ? error.get() : NULL,
                                 resp ? resp.get() : NULL, callback, context);
        ;
      });
}

// expandGroupNode
void bcos_rpc_expand_group_node(void *rpc, const char *group,
                                const char *node_info, rpc_callback callback,
                                void *context) {
  auto rpcPointer = (bcos::cppsdk::jsonrpc::JsonRpcInterface *)rpc;

  rpcPointer->expandGroupNode(
      group, node_info,
      [callback, context](bcos::Error::Ptr error,
                          std::shared_ptr<bcos::bytes> resp) {
        bcos_rpc_handle_response(error ? error.get() : NULL,
                                 resp ? resp.get() : NULL, callback, context);
        ;
      });
}

// removeGroup
void bcos_rpc_remove_group(void *rpc, const char *group, rpc_callback callback,
                           void *context) {
  auto rpcPointer = (bcos::cppsdk::jsonrpc::JsonRpcInterface *)rpc;

  rpcPointer->removeGroup(
      group, [callback, context](bcos::Error::Ptr error,
                                 std::shared_ptr<bcos::bytes> resp) {
        bcos_rpc_handle_response(error ? error.get() : NULL,
                                 resp ? resp.get() : NULL, callback, context);
        ;
      });
}

// recoverGroupNode
void bcos_rpc_recover_group_node(void *rpc, const char *group, const char *node,
                                 rpc_callback callback, void *context) {
  auto rpcPointer = (bcos::cppsdk::jsonrpc::JsonRpcInterface *)rpc;

  rpcPointer->recoverGroupNode(
      group, node,
      [callback, context](bcos::Error::Ptr error,
                          std::shared_ptr<bcos::bytes> resp) {
        bcos_rpc_handle_response(error ? error.get() : NULL,
                                 resp ? resp.get() : NULL, callback, context);
        ;
      });
}

// startNode
void bcos_rpc_start_node(void *rpc, const char *group, const char *node,
                         rpc_callback callback, void *context) {
  auto rpcPointer = (bcos::cppsdk::jsonrpc::JsonRpcInterface *)rpc;

  rpcPointer->startNode(group, node,
                        [callback, context](bcos::Error::Ptr error,
                                            std::shared_ptr<bcos::bytes> resp) {
                          bcos_rpc_handle_response(error ? error.get() : NULL,
                                                   resp ? resp.get() : NULL,
                                                   callback, context);
                        });
}

// stopNode
void bcos_rpc_stop_node(void *rpc, const char *group, const char *node,
                        rpc_callback callback, void *context) {
  auto rpcPointer = (bcos::cppsdk::jsonrpc::JsonRpcInterface *)rpc;

  rpcPointer->stopNode(group, node,
                       [callback, context](bcos::Error::Ptr error,
                                           std::shared_ptr<bcos::bytes> resp) {
                         bcos_rpc_handle_response(error ? error.get() : NULL,
                                                  resp ? resp.get() : NULL,
                                                  callback, context);
                       });
}

// getGroupList
void bcos_rpc_get_group_list(void *rpc, rpc_callback callback, void *context) {
  auto rpcPointer = (bcos::cppsdk::jsonrpc::JsonRpcInterface *)rpc;

  rpcPointer->getGroupList(
      [callback, context](bcos::Error::Ptr error,
                          std::shared_ptr<bcos::bytes> resp) {
        bcos_rpc_handle_response(error ? error.get() : NULL,
                                 resp ? resp.get() : NULL, callback, context);
        ;
      });
}

// getGroupInfoList
void bcos_rpc_get_group_info_list(void *rpc, rpc_callback callback,
                                  void *context) {
  auto rpcPointer = (bcos::cppsdk::jsonrpc::JsonRpcInterface *)rpc;

  rpcPointer->getGroupInfoList(
      [callback, context](bcos::Error::Ptr error,
                          std::shared_ptr<bcos::bytes> resp) {
        bcos_rpc_handle_response(error ? error.get() : NULL,
                                 resp ? resp.get() : NULL, callback, context);
        ;
      });
}

// getGroupInfo
void bcos_rpc_get_group_info(void *rpc, const char *group,
                             rpc_callback callback, void *context) {
  auto rpcPointer = (bcos::cppsdk::jsonrpc::JsonRpcInterface *)rpc;

  rpcPointer->getGroupInfo(
      group, [callback, context](bcos::Error::Ptr error,
                                 std::shared_ptr<bcos::bytes> resp) {
        bcos_rpc_handle_response(error ? error.get() : NULL,
                                 resp ? resp.get() : NULL, callback, context);
        ;
      });
}

// getGroupNodeInfo
void bcos_rpc_get_group_node_info(void *rpc, const char *group,
                                  const char *node, rpc_callback callback,
                                  void *context) {
  auto rpcPointer = (bcos::cppsdk::jsonrpc::JsonRpcInterface *)rpc;

  rpcPointer->getGroupNodeInfo(
      group, node,
      [callback, context](bcos::Error::Ptr error,
                          std::shared_ptr<bcos::bytes> resp) {
        bcos_rpc_handle_response(error ? error.get() : NULL,
                                 resp ? resp.get() : NULL, callback, context);
        ;
      });
}

// getNodeInfo // TODO: Temporary interface, should be removed in the end
void bcos_rpc_get_node_info(void *rpc, rpc_callback callback, void *context) {
  auto rpcPointer = (bcos::cppsdk::jsonrpc::JsonRpcInterface *)rpc;

  rpcPointer->getNodeInfo(
      [callback, context](bcos::Error::Ptr error,
                          std::shared_ptr<bcos::bytes> resp) {
        bcos_rpc_handle_response(error ? error.get() : NULL,
                                 resp ? resp.get() : NULL, callback, context);
        ;
      });
}

// ------------------------------rpc interface end -------------------------