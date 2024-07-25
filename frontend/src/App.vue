<template>
  <n-config-provider :theme="darkTheme">
    <n-message-provider>
      <n-modal-provider>
        <Layout></Layout>
      </n-modal-provider>
    </n-message-provider>
  </n-config-provider>
</template>

<script setup>
import Layout from './components/layout.vue';
import { darkTheme } from 'naive-ui'
</script>

<style lang="scss" scoped>
html,
body,
#app,
.n-config-provider {
  height: 100%;
}

.container {
  height: 100%;

  .n-layout-scroll-container {
    display: flex;
    flex-direction: column;
  }
}
</style>
