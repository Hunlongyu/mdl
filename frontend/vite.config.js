import { defineConfig } from 'vite'
import vue from '@vitejs/plugin-vue'
import AutoImport from 'unplugin-auto-import/vite'
import Components from 'unplugin-vue-components/vite'
import {
  NaiveUiResolver, VueUseComponentsResolver, VueUseDirectiveResolver
} from 'unplugin-vue-components/resolvers'

// https://vitejs.dev/config/
export default defineConfig({
  base: '/resources/',
  build: {
    outDir: '../backend/src/assets/html/',
    emptyOutDir: true,
  },
  plugins: [
    vue(),
    AutoImport({
      imports: [
        'vue',
        {
          'naive-ui': [
            'useDialog',
            'useMessage',
            'useNotification',
            'useLoadingBar'
          ]
        }
      ]
    }),
    Components({
      resolvers: [
        NaiveUiResolver(),
        VueUseComponentsResolver(),
        VueUseDirectiveResolver()
      ]
    })
  ]
})
