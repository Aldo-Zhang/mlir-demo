#include "Demo/DemoDialect.h"

#include <mlir/Interfaces/FunctionImplementation.h>

#define GET_OP_CLASSES
#include "Demo/DemoOps.cpp.inc"

namespace mlir {
namespace demo
{

// //
// // Addop
// //

// mlir::LogicalResult AddOp::inferReturnTypes(
//     ::mlir::MLIRContext *ctx, ::std::optional<::mlir::Location> location,
//     ::mlir::ValueRange operands, ::mlir::DictionaryAttr attrs,
//     ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions,
//     ::llvm::SmallVectorImpl<::mlir::Type> &inferredReturnTypes) {
//   const auto loc = location.value_or(mlir::UnknownLoc::get(ctx));
//   AddOpAdaptor add(operands, attrs);
//   if (mlir::failed(add.verify(loc))) {
//     return mlir::failure();
//   }

//   const auto inLhsType = mlir::cast<mlir::ShapedType>(add.getLhs().getType());
//   const auto inRhsType = mlir::cast<mlir::ShapedType>(add.getRhs().getType());

//   mlir::Type outType;
//   if (!inLhsType.hasRank() || !inRhsType.hasRank()) {
//     outType = mlir::UnrankedTensorType::get(inLhsType.getElementType());
//   } else {
//     outType = mlir::RankedTensorType::get(inLhsType.getShape(),
//                                           inLhsType.getElementType());
//   }
//   inferredReturnTypes.push_back(outType);
//   return mlir::success();
// }


} // namespace demo
} // namespace mlir