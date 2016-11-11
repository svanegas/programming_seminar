string buildTree(int inStart, int inEnd, int postStart, int postEnd) {
  if (inStart > inEnd || postStart > postEnd) return "";
  char rootValue = postorder[postEnd];
  int k = 0;
  for (int i = 0; i < inorder.size(); i++) {
    if (inorder[i] == rootValue) {
      k = i;
      break;
    }
  }

  string left = buildTree(inorder, inStart, k - 1, postorder, postStart,
                          postStart + k - (inStart + 1));
  // Becuase k is not the length, it it need to -(inStart+1) to get the length
  string right = buildTree(inorder, k + 1, inEnd, postorder,
                           postStart + k- inStart, postEnd - 1);
  // postStart+k-inStart = postStart+k-(inStart+1) +1

  return left + root + right;
}
