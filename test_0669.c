void trim(struct TreeNode* curr, struct TreeNode** parentSlot, int low, int high) {
    while (curr != NULL) {
        struct TreeNode* next;
        if (curr->val < low) {
            next = curr->right;
        } else if (curr->val > high) {
            next = curr->left;
        } else {
            break;
        }
        *parentSlot = next;
        curr = next;
    }
    if (curr == NULL) {
        return;
    }
    trim(curr->left, &curr->left, low, high);
    trim(curr->right, &curr->right, low, high);
}

struct TreeNode* trimBST(struct TreeNode* root, int low, int high) {
    struct TreeNode dummy;
    dummy.left = root;
    trim(root, &dummy.left, low, high);
    return dummy.left;
}
